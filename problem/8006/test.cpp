#include <bits/stdc++.h>

using namespace std;

const int INF = 987654321;

int V, E, K = 100;
vector<pair<int, int>> adj[101];
int ans[101][101][101];

void dijkstra(int s)
{
	vector<priority_queue<int>> d(V+1);
	
	priority_queue<pair<int, int>> pq;
	pq.push({0, s});

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
	{
		for(int k=K; k >= 1; k--)
		{
			if(d[i].size() < k)
				ans[s][i][k] = -1;
			else
			{
				ans[s][i][k] = d[i].top();
				d[i].pop();
			}
		}
	}
}

int main()
{
	scanf("%d%d", &V, &E);
	for(int i=0; i < E; i++)
	{
		int u, v, w;
		scanf("%d%d%d", &u, &v, &w);
		adj[u].push_back({v, w});
	}

	for(int i=1; i <= V; i++)
		dijkstra(i);

	int Q;
	scanf("%d", &Q);

	while(Q--)
	{
		int u, v, k;
		scanf("%d%d%d", &u, &v, &k);
		printf("%d\n", ans[u][v][k]);
	}
	return 0;
}