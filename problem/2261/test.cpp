#include <bits/stdc++.h>

using namespace std;

typedef pair<int,int> point;

int dist(const point& p, const point& q)
{
	return (p.first - q.first) * (p.first - q.first) + 
				(p.second - q.second) * (p.second - q.second);
}

bool cmp(const point& p, const point& q)
{
	return p.second < q.second;
}

int main()
{
	int N;
	scanf("%d",&N);

	vector<point> a(N);
	for(int i=0; i < N; i++)
		scanf("%d%d", &a[i].second, &a[i].first);

	sort(a.begin(), a.end(), cmp);

	set<point> candidate = {a[0], a[1]};
	int start = 0;
	int ans = dist(a[0], a[1]);

	for(int i=2; i < N; i++)
	{
		point& now = a[i];
		while(start < i)
		{
			int x = now.second - a[start].second;
			if(x * x > ans)
				candidate.erase(a[start++]);
			else
				break;
		}

		int d = (int)sqrt((double)ans) + 1;
		auto lo = candidate.lower_bound(point(now.first - d, -100000));
		auto hi = candidate.upper_bound(point(now.first + d, 100000));

		while(lo != hi)
		{
			ans = min(ans, dist(now, *lo));
			lo++;
		}

		candidate.insert(now);
	}

	printf("%d", ans);
	return 0;
}