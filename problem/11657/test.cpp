#include <bits/stdc++.h>

using namespace std;

const int INF = 987654321;

int N, M;
vector<pair<int, int>> adj[501];

void bellman_ford()
{
	vector<int> upper(N+1, INF);

	upper[1] = 0;
	bool updated;
	for(int iter=0; iter < N; iter++)
	{
		updated = false;

		for(int here=1; here <= N; here++)
			for(size_t i=0; i < adj[here].size(); i++)
			{
				int there = adj[here][i].first;
				int cost = adj[here][i].second;

				if(upper[there] > upper[here] + cost)
				{
					upper[there] = upper[here] + cost;
					updated = true;
				}
			}

		if(!updated)
			break;
	}
	if(updated)
	{
		puts("-1");
		return;
	}
	for(int i=2; i <= N; i++)
		printf("%d\n", upper[i] < INF / 2? upper[i]: -1);
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

	bellman_ford();
	return 0;
}