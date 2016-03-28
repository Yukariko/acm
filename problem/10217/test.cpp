#include <bits/stdc++.h>

using namespace std;

const int INF = 987654321;

int N, M, K;
vector<tuple<int, int, int>> adj[101];
int d[10001][101];

int solve()
{
	fill(&d[0][0], &d[M+1][0], INF);
	d[0][1] = 0;

	priority_queue<tuple<int, int, int>> pq;
	pq.push(make_tuple(0, 0, 1));

	while(!pq.empty())
	{
		int dist = -get<0>(pq.top());
		int cost = -get<1>(pq.top());
		int here = get<2>(pq.top());
		pq.pop();

		if(d[cost][here] < dist)
			continue;

		for(size_t i=0; i < adj[here].size(); i++)
		{
			int there = get<0>(adj[here][i]);
			int tcost = get<1>(adj[here][i]);
			int tdist = get<2>(adj[here][i]);

			if(cost + tcost <= M && d[cost + tcost][there] > d[cost][here] + tdist)
			{
				d[cost + tcost][there] = d[cost][here] + tdist;
				pq.push(make_tuple(-d[cost + tcost][there], -cost-tcost, there));
			}
		}
	}

	int ans = INF;
	for(int i=1; i <= M; i++)
		ans = min(ans, d[i][N]);
	return ans;
}

int main()
{
	int T;
	scanf("%d", &T);

	while(T--)
	{
		scanf("%d%d%d", &N, &M, &K);
		for(int i=1; i <= N; i++)
			adj[i].clear();

		while(K--)
		{
			int u, v, w, x;
			scanf("%d%d%d%d", &u, &v, &w, &x);
			adj[u].push_back(make_tuple(v, w, x));
		}

		int ans = solve();
		if(ans == INF)
			puts("Poor KCM");
		else
			printf("%d\n", ans);
	}
	return 0;
}