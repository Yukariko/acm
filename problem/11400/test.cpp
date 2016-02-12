#include <bits/stdc++.h>

using namespace std;

int V, E;
vector<vector<int>> adj;

vector<int> discovered;
vector<bool> isCutEdge;
int counter;

vector<pair<int, int>> ans;

int findCutEdge(int here, bool isRoot, int from)
{
	int ret = discovered[here] = counter++;

	isCutEdge[here] = true;

	for(size_t i=0; i < adj[here].size(); i++)
	{
		int there = adj[here][i];
		if(there == from)
			continue;
		if(discovered[there] == -1)
		{
			int subtree = findCutEdge(there, false, here);
			ret = min(ret, subtree);
		}
		else
			ret = min(ret, discovered[there]);
	}

	if(ret <= discovered[from])
		isCutEdge[here] = false;

	if(!isRoot && isCutEdge[here] == true)
		ans.push_back({min(from, here), max(from, here)});

	return ret;
}

int main()
{
	scanf("%d%d", &V, &E);

	adj.resize(V+1);
	discovered.resize(V+1, -1);
	isCutEdge.resize(V+1, false);

	for(int i=0; i < E; i++)
	{
		int u, v;
		scanf("%d%d", &u, &v);
		adj[u].push_back(v);
		adj[v].push_back(u);
	}

	for(int i=1; i <= V; i++)
		if(discovered[i] == -1)
			findCutEdge(i, true, 0);

	sort(ans.begin(), ans.end());
	printf("%d\n", ans.size());
	for(size_t i=0; i < ans.size(); i++)
		printf("%d %d\n", ans[i].first, ans[i].second);
	return 0;
}