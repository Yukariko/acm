#include <bits/stdc++.h>

using namespace std;

const int INF = 987654321;

int N, T, S, E;
int idx[1001];
int cnt;
int adj[101][101];

long long solve()
{
	vector<vector<int>> d(202, vector<int>(cnt+1, INF));
	vector<vector<int>> parent(202, vector<int>(cnt+1, -1));
	priority_queue<pair<int, pair<int, int>>> pq;

	d[0][S] = 0;
	pq.push({0, {0, S}});

	while(!pq.empty())
	{
		int size = pq.size();
		while(size--)
		{
			int dist = -pq.top().first;
			int nEdges = pq.top().second.first;
			int here = pq.top().second.second;
			pq.pop();

			if(nEdges == 201 || d[nEdges][here] > dist)
				continue;

			for(int there = 1; there <= cnt; there++)
			{
				if(adj[here][there] == 0)
					continue;
				int cost = adj[here][there];
				if(d[nEdges+1][there] > dist + cost)
				{
					d[nEdges+1][there] = dist + cost;
					parent[nEdges+1][there] = here;
					pq.push({-d[nEdges+1][there], {nEdges+1, there}});
				}
			}
		}
	}
	if(N < 202)
		return d[N][E];

	int check = N % 2? 201: 200;
	int curNode = E;
	int curEdges = check;
	int minCost = INF;
	while(curNode != -1)
	{
		int there = parent[curEdges][curNode];
		if(there == -1)
			break;
		minCost = min(minCost, adj[there][curNode]);
		curNode = there;
		curEdges--;
	}
	return d[check][E] + 1LL * (N - check) * minCost;
}

int main()
{
	scanf("%d%d%d%d", &N, &T, &S, &E);
	for(int i=0; i < T; i++)
	{
		int u, v, w;
		scanf("%d%d%d", &w, &u, &v);

		if(idx[u] == 0)
			idx[u] = ++cnt;
		if(idx[v] == 0)
			idx[v] = ++cnt;

		u = idx[u];
		v = idx[v];
		adj[u][v] = adj[v][u] = w;
	}

	S = idx[S];
	E = idx[E];

	printf("%lld", solve());
	return 0;
}