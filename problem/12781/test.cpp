#include <bits/stdc++.h>

using namespace std;

const double PI = 2.0 * acos(0.0);
const double EPSILON = 1e-9;

struct vector2
{
	double x, y;

	explicit vector2(double x = 0, double y = 0) : x(x), y(y) {}

	bool operator == (const vector2& rhs) const 
	{
		return x == rhs.x && y == rhs.y;
	}

	bool operator < (const vector2& rhs) const 
	{
		return x != rhs.x? x < rhs.x: y < rhs.y;
	}

	vector2 operator + (const vector2& rhs) const 
	{
		return vector2(x + rhs.x, y + rhs.y);
	}

	vector2 operator - (const vector2& rhs) const 
	{
		return vector2(x - rhs.x, y - rhs.y);
	}

	vector2 operator * (double rhs) const 
	{
		return vector2(x * rhs, y * rhs);
	}

	// 벡터의 길이
	double norm() const {return hypot(x, y);}

	vector2 normalize() const
	{
		return vector2(x / norm(), y / norm());
	}

	// x축의 양의 방향으로부터 이 벡터까지 반시계 방향으로 잰 각도
	double polar() const {return fmod(atan2(y, x) + 2 * PI, 2 * PI);}

	// 내적
	double dot(const vector2& rhs) const
	{
		return x * rhs.x + y * rhs.y;
	}

	// 외적
	double cross(const vector2& rhs) const
	{
		return x * rhs.y - y * rhs.x;
	}

	// rhs에 사영
	vector2 project(const vector2& rhs) const
	{
		vector2 r = rhs.normalize();
		return r * r.dot(*this);
	}
};

// 점 q가 다각형 p 안에 포함되어 있을 경우 true, 아닌경우 false
// q가 다각형의 경계위에 있는 경우는 정의되어 있지 않음
bool isInside(vector2 q, const vector<vector2>& p)
{
	int crosses = 0;
	for(int i=0; i < p.size(); i++)
	{
		int j = (i + 1) % p.size();

		if((p[i].y > q.y) != (p[j].y > q.y))
		{
			double atX = (p[j].x - p[i].x) * (q.y - p[i].y) / (p[j].y - p[i].y) + p[i].x;
			if(q.x < atX)
				crosses++;
		}
	}
	return crosses % 2 > 0;
}

// 주어지는 다각형의 넓이를 구함
double area(const vector<vector2>& p)
{
	double ret = 0;
	for(int i=0; i < p.size(); i++)
		ret += p[i].cross(p[(i + 1) % p.size()]);
	return fabs(ret) / 2.0;
}

// 두 직선의 교차점을 계산
bool lineIntersection(vector2 a, vector2 b, vector2 c, vector2 d, vector2 & x)
{
	double det = (b-a).cross(d-c);
	if(fabs(det) < EPSILON)
		return false;
	x = a + (b-a) * ((c-a).cross(d-c) / det);
	return true;
}

// 원점에서 벡터 b가 벡터 a의 반시계 방향이면 양수, 시계 방향이면 음수, 평행이면 0 반환
double ccw(vector2 a, vector2 b)
{
	return a.cross(b);
}

// 원점 대신 점 p를 기준으로 ccw
double ccw(vector2 p, vector2 a, vector2 b)
{
	return ccw(a-p,b-p);
}

// 두 평행한 선분의 교차점을 계산
bool parallelSegments(vector2 a, vector2 b, vector2 c, vector2 d, vector2& p)
{
	if(b < a)
		swap(a, b);
	if(d < c)
		swap(d, c);

	if(ccw(a, b, c) != 0 || b < c || d < a)
		return false;

	if(a < c)
		p = c;
	else
		p = a;
	return true;
}

// p가 (a, b)를 감싸면서 각 변이 x,y축에 평행한 최소 사각형 내부에 있는지 확인
// a, b, p는 일직선 상에 있다고 가정
bool inBoundingRectangle(vector2 p, vector2 a, vector2 b)
{
	if(b < a)
		swap(a, b);
	return p == a || p == b || (a < p && p < b);
}

// (a,b) 선분과 (c,d) 선분의 교점 x를 구함
// 교점이 여러개일 경우 아무거나, 없을경우 false를 반환
bool segmentIntersection(vector2 a, vector2 b, vector2 c, vector2 d, vector2& x)
{
	if(!lineIntersection(a,b,c,d,x))
		return false;
	return inBoundingRectangle(x, a, b) && inBoundingRectangle(x, c, d);
}


int main()
{
	vector<vector2> a;
	for(int i=0; i < 4; i++)
	{
		double x, y;
		scanf("%lf%lf", &x, &y);
		a.push_back(vector2(x, y));
	}

	vector2 t;
	if(!segmentIntersection(a[0], a[1], a[2], a[3], t))
		puts("0");
	else if(t == a[0] || t == a[1] || t == a[2] || t == a[3])
		puts("0");
	else
		puts("1");
	return 0;
}