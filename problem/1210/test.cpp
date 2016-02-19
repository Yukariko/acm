#include <bits/stdc++.h>

using namespace std;

const int INF = 987654321;

int V;
int capacity[401][401];
int flow[401][401];

class NetworkFlow
{
public:

	void addEdge(int u, int v, int cap)
	{
		capacity[u][v] = cap;
	}

	int getMaximumFlow(int source, int sink)
	{
		memset(flow, 0, sizeof(flow));

		int totalFlow = 0;
		while(true)
		{
			vector<int> parent(V, -1);

			queue<int> q;
			parent[source] = source;
			q.push(source);
			int here;

			while(!q.empty() && parent[sink] == -1)
			{
				here = q.front();
				q.pop();

				for(int there = 0; there < V; there++)
				{
					if(capacity[here][there] - flow[here][there] > 0 && parent[there] == -1)
					{
						q.push(there);
						parent[there] = here;
					}
				}
			}

			if(parent[sink] == -1)
			{
				break;
			}

			int amount = INF;
			for(int p = sink; p != source; p = parent[p])
				amount = min(amount, capacity[parent[p]][p] - flow[parent[p]][p]);

			totalFlow += amount;
			for(int p = sink; p != source; p = parent[p])
			{
				flow[parent[p]][p] += amount;
				flow[p][parent[p]] -= amount;
			}
		}

		return totalFlow;
	}
};

int N, M;

int in(int u)
{
	return u-1;
}

int out(int u)
{
	return N + u - 1;
}

bool visit[401];

void dfs(int here)
{
	visit[here] = true;
	for(int there = 0; there < V; there++)
		if(!visit[there] && capacity[here][there] - flow[here][there] > 0)
			dfs(there);
}

int main()
{
	scanf("%d%d", &N, &M);

	int S, E;
	scanf("%d%d", &S, &E);

	V = N * 2;
	NetworkFlow nf;

	for(int i=1; i <= N; i++)
	{
		int w;
		scanf("%d", &w);

		nf.addEdge(in(i), out(i), w);
	}

	for(int i=0; i < M; i++)
	{
		int u, v;
		scanf("%d%d", &u, &v);

		nf.addEdge(out(u), in(v), INF);
		nf.addEdge(out(v), in(u), INF);
	}

	nf.getMaximumFlow(in(S), out(E));

	dfs(in(S));

	for(int i=1; i <= N; i++)
		if(visit[in(i)] && !visit[out(i)])
			printf("%d ", i);
	return 0;
}