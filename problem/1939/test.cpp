#include <bits/stdc++.h>

using namespace std;

int N, M;
vector<pair<int, int>> adj[100001];
int P, Q;

bool solve(int size)
{
	vector<bool> visit(N+1, false);
	queue<int> bfs;

	visit[P] = true;
	bfs.push(P);

	while(!bfs.empty())
	{
		int here = bfs.front();
		bfs.pop();

		if(here == Q)
			return true;

		for(size_t i=0; i < adj[here].size(); i++)
		{
			int there = adj[here][i].first;
			int cost = adj[here][i].second;
			if(!visit[there] && cost > size)
			{
				visit[there] = true;
				bfs.push(there);
			}
		}
	}
	return false;
}

int main()
{
	scanf("%d%d", &N, &M);
	while(M--)
	{
		int u, v, w;
		scanf("%d%d%d", &u, &v, &w);
		adj[u].push_back({v, w});
		adj[v].push_back({u, w});
	}
	scanf("%d%d", &P, &Q);

	int left = 0, right = 1000000000;
	while(left <= right)
	{
		int mid = (left + right) / 2;
		if(solve(mid))
			left = mid + 1;
		else
			right = mid - 1;
	}

	printf("%d", left);
	return 0;
}