#include <bits/stdc++.h>

using namespace std;

const int INF = 987654321;

int V, E, K;
vector<pair<int, int>> adj[1001];

void dijkstra()
{
	vector<priority_queue<int>> d(V+1);
	d[1].push(0);
	
	priority_queue<pair<int, int>> pq;
	pq.push({0, 1});

	while(!pq.empty())
	{
		int dist = -pq.top().first;
		int here = pq.top().second;
		pq.pop();

		for(size_t i=0; i < adj[here].size(); i++)
		{
			int there = adj[here][i].first;
			int cost = adj[here][i].second;

			if(d[there].size() < K || d[there].top() > dist + cost)
			{
				d[there].push(dist + cost);
				if(d[there].size() > K)
					d[there].pop();
				pq.push({-dist-cost, there});
			}
		}
	}

	for(int i=1; i <= V; i++)
		printf("%d\n", d[i].size() < K? -1: d[i].top());
}

int main()
{
	scanf("%d%d%d", &V, &E, &K);
	for(int i=0; i < E; i++)
	{
		int u, v, w;
		scanf("%d%d%d", &u, &v, &w);
		adj[u].push_back({v, w});
	}

	dijkstra();
	return 0;
}