#include <bits/stdc++.h>

using namespace std;

const int INF = 987654321;

int V, E;
int S, D;
int adj[501][501];

int dijkstra()
{
	vector<int> d(V+1, INF);
	vector<vector<int>> parent(V+1);

	priority_queue<pair<int, int>> pq;

	d[S] = 0;
	pq.push({0, S});

	while(!pq.empty())
	{
		int here = pq.top().second;
		int dist = -pq.top().first;
		pq.pop();

		if(d[here] < dist)
			continue;

		for(int there=0; there < V; there++)
		{
			int cost = adj[here][there];
			if(cost == -1)
				continue;

			if(d[there] > d[here] + cost)
			{
				d[there] = d[here] + cost;
				pq.push({-d[there], there});
				parent[there].clear();
			}

			if(d[there] == d[here] + cost)
				parent[there].push_back(here);
		}
	}

	queue<pair<int, int>> bfs;
	for(size_t i=0; i < parent[D].size(); i++)
		bfs.push({D, parent[D][i]});
	
	while(!bfs.empty())
	{
		int there = bfs.front().first;
		int here = bfs.front().second;
		bfs.pop();

		adj[here][there] = -1;
		for(size_t i=0; i < parent[here].size(); i++)
			bfs.push({here, parent[here][i]});
	}
	return d[D] == INF? -1: d[D];
}


int main()
{
	while(scanf("%d%d", &V, &E), V)
	{
		scanf("%d%d", &S, &D);
		memset(adj, -1, sizeof(adj));

		for(int i=0; i < E; i++)
		{
			int u, v, w;
			scanf("%d%d%d", &u, &v, &w);
			adj[u][v] = w;
		}

		dijkstra();
		printf("%d\n", dijkstra());
	}
	return 0;
}