//dijkstra
#include <bits/stdc++.h>

using namespace std;

const int INF = 987654321;

int V, E;
int s, e;

vector<vector<pair<int, int>>> adj;

void dijkstra()
{
	vector<int> d(V+1, 0);
	vector<vector<int>> parent(V+1);

	priority_queue<pair<int, int>> pq;
	pq.push({0, s});

	while(!pq.empty())
	{
		int here = pq.top().second;
		int dist = pq.top().first;
		pq.pop();

		if(d[here] > dist)
			continue;

		for(size_t i=0; i < adj[here].size(); i++)
		{
			int there = adj[here][i].first;
			int w = adj[here][i].second;
			if(d[there] < d[here] + w)
			{
				d[there] = d[here] + w;
				parent[there].clear();
				pq.push({d[there], there});
			}

			if(d[there] == d[here] + w)
				parent[there].push_back(here);
		}
	}

	printf("%d\n", d[e]);

	int ans = 0;
	queue<int> bfs;
	bfs.push(e);
	while(!bfs.empty())
	{
		int here = bfs.front();
		bfs.pop();

		while(!parent[here].empty())
		{
			int there = parent[here].back();
			parent[here].pop_back();

			ans++;
			bfs.push(there);
		}
	}

	printf("%d", ans);
}

int main()
{
	scanf("%d%d", &V, &E);

	adj.resize(V+1);
	for(int i=0; i < E; i++)
	{
		int u, v, w;
		scanf("%d%d%d", &u, &v, &w);
		adj[u].push_back({v, w});
	}
	scanf("%d%d", &s, &e);

	dijkstra();
	return 0;
}