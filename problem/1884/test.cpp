#include <bits/stdc++.h>

using namespace std;

struct edge
{
	int v, w, m;
	bool operator<(const edge& q) const
	{
		return w < q.w;
	}
};

const int INF = 987654321;

int K, V, E;
vector<edge> adj[101];
int d[101][10001];

int dijkstra()
{
	fill(&d[0][0], &d[101][0], INF);
	d[1][0] = 0;
	priority_queue<edge> pq;
	pq.push({1, 0, 0});

	while(!pq.empty())
	{
		edge cur =  pq.top();
		pq.pop();

		if(cur.v == V)
			return -cur.w;

		if(d[cur.v][cur.m] < -cur.w)
			continue;

		for(size_t i=0; i < adj[cur.v].size(); i++)
		{
			edge& there = adj[cur.v][i];
			if(cur.m + there.m <= K && d[there.v][cur.m + there.m] > -cur.w + there.w)
			{
				d[there.v][cur.m + there.m] = -cur.w + there.w;
				pq.push({there.v, cur.w - there.w, cur.m + there.m});
			}
		}
	}
	return -1;
}

int main()
{
	scanf("%d%d%d", &K, &V, &E);
	for(int i=0; i < E; i++)
	{
		int u, v, w, m;
		scanf("%d%d%d%d", &u, &v, &w, &m);
		adj[u].push_back({v, w, m});
	}

	printf("%d", dijkstra());
	return 0;
}