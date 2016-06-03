#include <iostream>
#include <algorithm>
#include <cstring>
#include <vector>
#include <cstdio>
#include <map>
#include <cmath>
#include <cassert>

using namespace std;


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

double area(const vector<vector2>& p)
{
	double ret = 0;
	for(int i=0; i < p.size(); i++)
		ret += p[i].cross(p[(i + 1) % p.size()]);
	return fabs(ret) / 2.0;
}

bool lineIntersection(vector2 a, vector2 b, vector2 c, vector2 d, vector2 & x)
{
	double det = (b-a).cross(d-c);
	if(fabs(det) < EPSILON)
		return false;
	x = a + (b-a) * ((c-a).cross(d-c) / det);
	return true;
}

double ccw(vector2 a, vector2 b)
{
	return a.cross(b);
}

double ccw(vector2 p, vector2 a, vector2 b)
{
	return ccw(a-p,b-p);
}

int parallelSegments(vector2 a, vector2 b, vector2 c, vector2 d, vector2& p)
{
	if(b < a)
		swap(a, b);
	if(d < c)
		swap(d, c);

	if(ccw(a, b, c) != 0 || b < c || d < a)
		return 0;

	if(a < c)
		p = c;
	else
		p = a;

	if(a.x == c.x && b.x == c.x)
	{
		if(a.y == d.y || b.y == c.y)
			return 1;
		return 10;
	}

	if(a.y == c.y && b.y == c.y)
	{
		if(a.x == d.x || b.x == c.x)
			return 1;
		return 10;
	}
	return 1;
}

bool inBoundingRectangle(vector2 p, vector2 a, vector2 b)
{
	if(b < a)
		swap(a, b);
	return p == a || p == b || (a < p && p < b);
}

int segmentIntersection(vector2 a, vector2 b, vector2 c, vector2 d, vector2& t)
{
	if(!lineIntersection(a,b,c,d,t))
		return parallelSegments(a,b,c,d,t);
	return inBoundingRectangle(t, a, b) && inBoundingRectangle(t, c, d);
}

typedef vector<vector2> polygon;

int main()
{
	int T;
	cin >> T;

	while(T--)
	{
		int x1,y1,x2,y2;
		cin >> x1 >> y1 >> x2 >> y2;

		int a1,b1,a2,b2;
		cin >> a1 >> b1 >> a2 >> b2;
		if(a1 > a2)
			swap(a1, a2);
		if(b1 > b2)
			swap(b1, b2);
		polygon p;
		p.push_back(vector2(a1,b2));
		p.push_back(vector2(a1,b1));
		p.push_back(vector2(a2,b1));
		p.push_back(vector2(a2,b2));

		int ans = 0;
		int point = 0;
		for(int i=0; i < 4; i++)
		{
			vector2 t(-123123,-123123);
			int k = segmentIntersection(p[i], p[(i+1)%4], vector2(x1,y1), vector2(x2,y2), t);
			if(k && (t == p[i] || t == p[(i + 1) % 4]))
			{
				point++;
				ans+= k;
			}

			else
				ans += k;
		}

		if(ans)
			puts("T");
		else
		{
			if(a1 < x1 && x1 < a2 && a1 < x2 && x2 < a2 && b1 < y1 && y1 < b2 && b1 < y2 && y2 < b2)	
				puts("T");
			else
				puts("F");
		}
	}
	return 0;
}
