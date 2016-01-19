#include <bits/stdc++.h>

using namespace std;

vector<int> adj[101];
bool visit[101];

void solve(int here)
{
	for(int there=0; there < adj[here].size(); there++)
	{
		if(visit[adj[here][there]])
		{
			puts("CYCLE");
			exit(0);
		}

		visit[adj[here][there]] = true;
		solve(adj[here][there]);
		visit[adj[here][there]] = false;
	}
}

int main()
{
	int N;
	scanf("%d", &N);

	for(int i=1; i < N; i++)
	{
		int M;
		scanf("%d", &M);

		for(int j=0; j < M; j++)
		{
			int v;
			scanf("%d", &v);
			adj[i].push_back(v);
		}
	}

	visit[1] = true;
	solve(1);
	puts("NO CYCLE");
	return 0;
}