#include <bits/stdc++.h>

using namespace std;

const int INF = 987654321;

int N, M;
vector<pair<int, int>> adj[1001];

bool visit[1001];

int solve(int here)
{
	visit[here] = true;
	if(adj[here].size() == 0)
		return 0;

	int ans = 0;
	for(size_t i=0; i < adj[here].size(); i++)
	{
		int there = adj[here][i].first;
		int cost = adj[here][i].second;
		if(!visit[there])
			ans += min(cost, solve(there));
	}

	if(ans == 0)
		ans = INF;
	return ans;
}

int main()
{
	int T;
	scanf("%d", &T);

	while(T--)
	{
		scanf("%d%d", &N, &M);
		for(int i=1; i <= N; i++)
			adj[i].clear();
		memset(visit, false, sizeof(visit));

		for(int i=0; i < M; i++)
		{
			int u, v, w;
			scanf("%d%d%d", &u, &v, &w);
			adj[u].push_back({v, w});
			adj[v].push_back({u, w});
		}

		printf("%d\n", solve(1));
	}
	return 0;
}