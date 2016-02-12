#include <bits/stdc++.h>

using namespace std;

int N, M;

vector<vector<int>> adj;

vector<int> discovered;
int counter = 0;

vector<bool> isCutVertex;

vector<int> ans;

int findCutvertex(int here, bool isRoot)
{
	discovered[here] = counter++;

	int ret = discovered[here];
	int child = 0;

	for(size_t i=0; i < adj[here].size(); i++)
	{
		int there = adj[here][i];
		if(discovered[there] == -1)
		{
			child++;

			int subtree = findCutvertex(there, false);

			if(!isRoot && subtree >= discovered[here])
				isCutVertex[here] = true;
			ret = min(ret, subtree);
		}
		else
			ret = min(ret, discovered[there]);
	}

	if(isRoot) isCutVertex[here] = child >= 2;
	if(isCutVertex[here] == true)
		ans.push_back(here);
	return ret;
}

int main()
{
	scanf("%d%d", &N, &M);

	adj.resize(N+1);
	discovered.resize(N+1, -1);
	isCutVertex.resize(N+1, false);

	for(int i=0; i < M; i++)
	{
		int u, v;
		scanf("%d%d", &u, &v);
		adj[u].push_back(v);
		adj[v].push_back(u);
	}

	for(int i=1; i <= N; i++)
		if(discovered[i] == -1)
			findCutvertex(i, true);

	sort(ans.begin(), ans.end());
	printf("%d\n", ans.size());
	for(size_t i=0; i < ans.size(); i++)
		printf("%d ", ans[i]);
	return 0;
}