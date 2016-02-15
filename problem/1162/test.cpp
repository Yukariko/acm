// dijkstra
#include <bits/stdc++.h>

using namespace std;

const int INF = 987654321;

int V, E, K;

vector<vector<pair<int,int>>> adj;

int dijkstra()
{
	vector<vector<int>> d(K+1, vector<int>(V+1, INF));
	d[0][1] = 0;

	priority_queue<pair<int, pair<int, int>>> pq;
	pq.push({0, {0, 1}});

	while(!pq.empty())
	{
		int cost = -pq.top().first;
		int k = pq.top().second.first;
		int here = pq.top().second.second;
		pq.pop();

		if(d[k][here] < cost)
			continue;

		for(size_t i=0; i < adj[here].size(); i++)
		{
			int there = adj[here][i].first;
			int w = adj[here][i].second;
			if(d[k][there] > d[k][here] + w)
			{
				d[k][there] = d[k][here] + w;
				pq.push({-d[k][there], {k, there}});
			}
			if(k < K && d[k+1][there] > d[k][here])
			{
				d[k+1][there] = d[k][here];
				pq.push({-d[k+1][there], {k+1, there}});	
			}
		}
	}

	return d[K][V];
}

int main()
{
	scanf("%d%d%d", &V, &E, &K);
	adj.resize(V + 1);

	for(int i=0; i < E; i++)
	{
		int u, v, w;
		scanf("%d%d%d", &u, &v, &w);

		adj[u].push_back({v, w});
		adj[v].push_back({u, w});
	}

	printf("%d", dijkstra());
	return 0;
}
