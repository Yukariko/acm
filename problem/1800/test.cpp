#include <bits/stdc++.h>

using namespace std;

struct DisjointSet {
	vector<int> group;
	DisjointSet(int N)
	{
		group.resize(N);
		for(int i=0; i < N; i++)
			group[i] = i;
	}

	int find(int n)
	{
		if(group[n] == n)
			return n;
		return group[n] = find(group[n]);
	}

	void merge(int p, int q)
	{
		p = find(p);
		q = find(q);
		if(p != q)
			group[p] = q;
	}
};

const int INF = 987654321;

int V, E, K;
vector<pair<int, pair<int, int>>> edges;

bool solve(int limit)
{
	DisjointSet djs(V+1);

	for(int i=0; i < E; i++)
		if(edges[i].first < limit)
			djs.merge(edges[i].second.first, edges[i].second.second);

	vector<vector<int>> adj(V+1);

	for(int i=0; i < E; i++)
	{
		int here = djs.find(edges[i].second.first);
		int there = djs.find(edges[i].second.second);
		if(edges[i].first >= limit && here != there)
		{
			adj[here].push_back(there);
			adj[there].push_back(here);
		}
	}

	vector<bool> visit(V+1, false);
	queue<int> bfs;

	visit[djs.find(1)] = true;
	bfs.push(djs.find(1));

	for(int d=0; d <= K && !bfs.empty(); d++)
	{
		int size = bfs.size();
		while(size--)
		{
			int here = bfs.front();
			bfs.pop();

			if(here == djs.find(V))
				return true;

			for(size_t i=0; i < adj[here].size(); i++)
			{
				int there = adj[here][i];
				if(!visit[there])
				{
					visit[there] = true;
					bfs.push(there);
				}
			}
		}
	}

	return false;
}

int main()
{
	scanf("%d%d%d", &V, &E, &K);

	int maxCost = 0;
	for(int i=0; i < E; i++)
	{
		int u, v, w;
		scanf("%d%d%d", &u, &v, &w);

		edges.push_back({w, {u, v}});
		maxCost = max(maxCost, w);
	}

	int left = 1, right = maxCost;
	while(left <= right)
	{
		int mid = (left + right) / 2;
		if(solve(mid))
			right = mid - 1;
		else
			left = mid + 1;
	}

	printf("%d", left == maxCost + 1? -1: right);
	return 0;
}