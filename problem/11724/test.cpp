#include <bits/stdc++.h>

using namespace std;

int V, E;

vector<vector<int>> adj;

vector<bool> visit;

void dfs(int here)
{
	visit[here] = true;
	for(size_t i=0; i < adj[here].size(); i++)
		if(visit[adj[here][i]] == false)
			dfs(adj[here][i]);
}

int main()
{
	scanf("%d%d", &V, &E);

	adj.resize(V+1);
	visit.resize(V+1, false);

	for(int i=0; i < E; i++)
	{
		int u, v;
		scanf("%d%d", &u, &v);
		adj[u].push_back(v);
		adj[v].push_back(u);
	}

	int ans = 0;
	for(int i=1; i <= V; i++)
		if(visit[i] == false)
			dfs(i), ans++;

	printf("%d", ans);
	return 0;
}