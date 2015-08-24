#include <iostream>
#include <algorithm>
#include <cstring>
#include <vector>
#include <cstdio>
#include <map>

using namespace std;

const long long dy[] ={0,-1,0,1};
const long long dx[] ={1,0,-1,0};

#define LEFTROTATE(d) (d == 0? 3: d-1)
#define RIGHTROTATE(d) (d == 3? 0: d+1)

#define RIGHT 0
#define DOWN 1
#define LEFT 2
#define UP 3

const long long INF = 987987654321LL;

struct line
{
	long long x, y, l;
	int d;
	line(long long x, long long y, long long l, int d) : x(x), y(y), l(l), d(d)
	{
		if(d == LEFT || d == DOWN)
			this->l = -l;
	}
};

bool inside(long long p, long long q, long long r)
{
	if(p > q)
		swap(p,q);
	return p <= r && r <= q;
}

long long intersection(const line& p, const line& q)
{
	if(p.d == RIGHT || p.d == LEFT)
	{
		if(q.d == UP || q.d == DOWN)
		{
			if(inside(p.x, p.x + p.l, q.x) && inside(q.y, q.y + q.l, p.y))
				return llabs(q.x - p.x);
			return INF;
		}

		long long x = q.x;
		if(p.d != q.d)
			x = q.x + q.l;
		if(p.y == q.y && inside(p.x, p.x + p.l, x))
			return llabs(x - p.x);
		return INF;
	}

	if(p.d == UP || p.d == DOWN)
	{
		if(q.d == RIGHT || q.d == LEFT)
		{
			if(inside(p.y, p.y + p.l, q.y) && inside(q.x, q.x + q.l, p.x))
				return llabs(q.y - p.y);
			return INF;
		}

		long long y = q.y;
		if(p.d != q.d)
			y = q.y + q.l;

		if(p.x == q.x && inside(p.y, p.y + p.l, y))
			return llabs(y - p.y);
		return INF;
	}
	return 0;
}

int main()
{
	long long L, N;
	cin >> L >> N;

	vector<line> wall;
	wall.push_back(line(-L-1,L+1, 2 * L + 3, RIGHT));
	wall.push_back(line(-L-1,L+1, 2 * L + 3, DOWN));
	wall.push_back(line(L+1,-L-1, 2 * L + 3, LEFT));
	wall.push_back(line(L+1,-L-1, 2 * L + 3, UP));

	long long time = 0;
	long long y=0, x=0;
	int d = RIGHT;

	N++;
	while(N--)
	{
		long long T;
		char D;

		if(N)
			cin >> T >> D;
		else
			T = 10 * L;

		line current(x, y, T, d);

		long long dist = INF;
		for(int i=0; i < wall.size(); i++)
			dist = min(dist, intersection(current, wall[i]));

		if(dist != INF)
		{
			cout << time + dist;
			return 0;
		}

		wall.push_back(line(x, y, T-1, d));
		time += T;
		y = y + dy[d] * T;
		x = x + dx[d] * T;
		if(D == 'L')
			d = LEFTROTATE(d);
		else
			d = RIGHTROTATE(d);
	}
	return 0;
}