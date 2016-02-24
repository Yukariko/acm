#include <bits/stdc++.h>

using namespace std;

int V, E, N;
vector<int> adj[1001];
vector<int> rev_adj[1001];

set<int> causes[1001];

bool occurred[1001];
int ancient[1001];

void fill_true(int here)
{
	occurred[here] = true;
	for(size_t i=0; i < adj[here].size(); i++)
	{
		int there = adj[here][i];
		if(occurred[there] == false)
			fill_true(there);
	}
}

void detection(int here)
{
	if(rev_adj[here].empty())
	{
		causes[here].insert(here);
		return;
	}

	for(size_t i=0; i < rev_adj[here].size(); i++)
	{
		int there = rev_adj[here][i];
		if(causes[there].empty())
			detection(there);

		for(auto &pick : causes[there])
			causes[here].insert(pick);
	}
}

int main()
{
	scanf("%d%d%d", &V, &E, &N);
	for(int i=0; i < E; i++)
	{
		int u, v;
		scanf("%d%d", &u, &v);

		adj[u].push_back(v);
		rev_adj[v].push_back(u);
	}

	vector<int> a(N);
	for(int i=0; i < N; i++)
	{
		scanf("%d", &a[i]);
		if(!occurred[a[i]])
			fill_true(a[i]);
	}

	for(int i=1; i <= V; i++)
		if(causes[i].empty())
			detection(i);

	for(int i=1; i <= V; i++)
	{
		if(occurred[i])
			continue;

		for(int j=0; j < N; j++)
		{
			bool find = true;
			for(auto &pick : causes[a[j]])
			{
				if(causes[i].count(pick) == 0)
				{
					find = false;
					break;
				}
			}

			if(find == false)
				continue;

			occurred[i] = true;
			fill_true(i);
		}
	}

	for(int i=1; i <= V; i++)
		if(occurred[i])
			printf("%d ", i);

	return 0;
}