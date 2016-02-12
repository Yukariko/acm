#include <bits/stdc++.h>

using namespace std;

int V, E;

vector<vector<int>> adj;

vector<int> sccId, discovered, finished;
int sccCounter, vertexCounter;
stack<int> st;

vector<vector<int>> ans;

int scc(int here)
{
	int ret = discovered[here] = vertexCounter++;
	st.push(here);

	for(size_t i=0; i < adj[here].size(); i++)
	{
		int there = adj[here][i];

		if(discovered[there] == -1)
			ret = min(ret, scc(there));
		else if(discovered[there] < discovered[here] && finished[there] != 1)
			ret = min(ret, discovered[there]);
	}

	if(ret == discovered[here])
	{
		ans.push_back(vector<int>());
		while(true)
		{
			int t = st.top();
			st.pop();
			sccId[t] = sccCounter;
			ans[sccCounter].push_back(t);
			finished[t] = 1;
			if(t == here)
				break;
		}
		sccCounter++;
	}

	return ret;
}

void tarjanSCC()
{
	sccId = discovered = finished = vector<int>(adj.size(), -1);
	sccCounter = vertexCounter = 0;

	for(int i=1; i <= V; i++)
		if(discovered[i] == -1)
			scc(i);
}

int main()
{
	scanf("%d%d", &V, &E);

	adj.resize(V+1);

	for(int i=0; i < E; i++)
	{
		int u, v;
		scanf("%d%d", &u, &v);
		adj[u].push_back(v);
	}

	tarjanSCC();

	for(int i=0; i < sccCounter; i++)
		sort(ans[i].begin(), ans[i].end());
	sort(ans.begin(), ans.end());

	printf("%d\n", sccCounter);
	for(int i=0; i < sccCounter; i++)
	{
		for(size_t j=0; j < ans[i].size(); j++)
			printf("%d ", ans[i][j]);
		puts("-1");
	}
	return 0;
}