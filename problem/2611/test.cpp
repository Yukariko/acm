#include <bits/stdc++.h>

using namespace std;

int N, M;
vector<pair<int, int>> adj[1001];

void dijkstra()
{
	vector<int> d(N+1, 0);
	vector<int> parent(N+1, -1);

	priority_queue<pair<int,int>> pq;
	pq.push({0, 1});

	int ans = 0;
	while(!pq.empty())
	{
		int here = pq.top().second;
		int score = pq.top().first;
		pq.pop();

		if(d[here] > score)
			continue;

		if(here == 1 && score > 0)
		{
			ans = max(ans, score);
			continue;
		}

		for(size_t i=0; i < adj[here].size(); i++)
		{
			int there = adj[here][i].first;
			int ts = adj[here][i].second;
			if(d[there] < d[here] + ts)
			{
				d[there] = d[here] + ts;
				parent[there] = here;
				pq.push({d[there], there});
			}
		}
	}

	printf("%d\n", ans);

	vector<int> paths;
	int here = 1;
	while(here != -1)
	{
		paths.push_back(here);
		if(parent[here] == 1)
		{
			paths.push_back(1);
			break;
		}
		here = parent[here];
	}

	reverse(paths.begin(), paths.end());
	for(size_t i=0; i < paths.size(); i++)
		printf("%d ", paths[i]);
}

int main()
{
	scanf("%d%d", &N, &M);
	while(M--)
	{
		int u, v, w;
		scanf("%d%d%d", &u, &v, &w);
		adj[u].push_back({v, w});
	}

	dijkstra();
	return 0;
}