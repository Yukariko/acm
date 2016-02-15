#include <bits/stdc++.h>

using namespace std;

int V, E;
vector<vector<int>> adj;

int color[20001];

bool part(int here, int col)
{
	color[here] = col;

	for(size_t i=0; i < adj[here].size(); i++)
	{
		int there = adj[here][i];
		if(color[there] == col)
			return false;
		
		if(color[there] == -1 && !part(there, !col))
			return false;
	}
	return true;
}

int main()
{
	int T;
	scanf("%d", &T);

	while(T--)
	{
		scanf("%d%d", &V, &E);

		adj.clear();
		adj = vector<vector<int>>(V+1);
		memset(color, -1, sizeof(color));

		for(int i=0; i < E; i++)
		{
			int u, v;
			scanf("%d%d", &u, &v);
			adj[u].push_back(v);
			adj[v].push_back(u);
		}

		bool find = true;
		for(int i=1; i <= V; i++)
			if(color[i] == -1 && !part(i, 0))
			{
				find = false;
				break;
			}
		puts(find? "YES": "NO");
	}
	return 0;
}