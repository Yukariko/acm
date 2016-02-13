#include <bits/stdc++.h>

using namespace std;

int N, M;
vector<vector<int>> adj;

int idx(int n)
{
	return abs(n) * 2 + (n < 0);
}

void makeGraph(const vector<pair<int, int>>& clause)
{
	adj.clear();
	adj.resize((N + 1) * 2);

	for(int i=0; i < M; i++)
	{
		adj[idx(-clause[i].first)].push_back(idx(clause[i].second));
		adj[idx(-clause[i].second)].push_back(idx(clause[i].first));
	}
}


vector<int> sccId, discovered, finished;
int sccCounter, vertexCounter;
stack<int> st;

int scc(int here)
{
	int ret = discovered[here] = vertexCounter++;
	st.push(here);

	for(size_t i=0; i < adj[here].size(); i++)
	{
		int there = adj[here][i];

		if(discovered[there] == -1)
			ret = min(ret, scc(there));
		else if(finished[there] != 1)
			ret = min(ret, discovered[there]);
	}

	if(ret == discovered[here])
	{
		while(true)
		{
			int t = st.top();
			st.pop();
			sccId[t] = sccCounter;
			finished[t] = 1;
			if(t == here)
				break;
		}
		sccCounter++;
	}

	return ret;
}

vector<int> tarjanSCC()
{
	sccId = discovered = finished = vector<int>(adj.size(), -1);
	sccCounter = vertexCounter = 0;

	for(int i=2; i < adj.size(); i++)
		if(discovered[i] == -1)
			scc(i);
	return sccId;
}



bool solve2SAT(vector<int>& value)
{
	int n = adj.size();
	vector<int> label = tarjanSCC();

	for(int i=2; i < n; i+=2)
		if(label[i] == label[i+1])
			return false;

	value = vector<int>(n / 2, -1);

	vector<pair<int, int>> order;
	for(int i=2; i < n; i++)
		order.push_back({-label[i], i});

	sort(order.begin(), order.end());

	for(size_t i=0; i < order.size(); i++)
	{
		int vertex = order[i].second;
		int variable = vertex / 2, isTrue = vertex % 2 == 0;
		if(value[variable] != -1)
			continue;
		value[variable] = !isTrue;
	}
	return true;
}

int main()
{
	scanf("%d%d", &N, &M);

	vector<pair<int, int>> a(M);
	for(int i=0; i < M; i++)
		scanf("%d%d", &a[i].first, &a[i].second);

	makeGraph(a);

	vector<int> ans;
	printf("%d\n", solve2SAT(ans));
	return 0;
}