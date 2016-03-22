#include <bits/stdc++.h>

using namespace std;

const int INF = 987654321;

int N, M;
vector<pair<int, int>> adj[1001];

void dijkstra(int start, int end)
{
	vector<int> d(N+1, INF);
	vector<int> sel(N+1, -1);
	priority_queue<pair<int, int>> pq;

	d[start] = 0;
	pq.push({0, start});

	while(!pq.empty())
	{
		int dist = -pq.top().first;
		int here = pq.top().second;
		pq.pop();

		if(d[here] < dist)
			continue;

		for(size_t i=0; i < adj[here].size(); i++)
		{
			int there = adj[here][i].first;
			int cost = adj[here][i].second;
			if(d[here] + cost < d[there])
			{
				d[there] = d[here] + cost;
				sel[there] = here;
				pq.push({-d[there], there});
			}
		}
	}

	printf("%d\n", d[end]);

	vector<int> paths;
	while(end != -1)
	{
		paths.push_back(end);
		end = sel[end];
	}

	reverse(paths.begin(), paths.end());

	printf("%d\n", paths.size());
	for(size_t i=0; i < paths.size(); i++)
		printf("%d ", paths[i]);
	puts("");
}

int main()
{
	scanf("%d%d", &N, &M);
	for(int i=0; i < M; i++)
	{
		int u, v, w;
		scanf("%d%d%d", &u, &v, &w);
		adj[u].push_back({v, w});
	}

	int S, E;
	scanf("%d%d", &S, &E);
	dijkstra(S, E);
	return 0;
}