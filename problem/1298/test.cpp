#include <bits/stdc++.h>

using namespace std;

const int INF = 987654321;

int N, M;
int V;
int cap[202][202];
int flow[202][202];

void addEdge(int u, int v, int w)
{
	cap[u][v] = w;
}

int in(int v)
{
	return v;
}

int out(int v)
{
	return N + v;
}

int maximumFlow(int source, int sink)
{

	int totalFlow = 0;

	while(true)
	{
		vector<int> parent(V, -1);
		queue<int> q;

		parent[source] = source;
		q.push(source);
		while(!q.empty() && parent[sink] == -1)
		{
			int here = q.front();
			q.pop();

			for(int there = 0; there < V; there++)
			{
				if(cap[here][there] - flow[here][there] > 0 && parent[there] == -1)
				{
					q.push(there);
					parent[there] = here;
				}
			}
		}
		if(parent[sink] == -1)
			break;

		int amount = INF;
		for(int p = sink; p != source; p = parent[p])
			amount = min(amount, cap[parent[p]][p] - flow[parent[p]][p]);

		for(int p = sink; p != source; p = parent[p])
			flow[parent[p]][p] += amount, flow[p][parent[p]] -= amount;

		totalFlow += amount;
	}
	return totalFlow;
}

int main()
{
	scanf("%d%d", &N, &M);
	V = 2 * N + 2;
	int source = 0;
	int sink = 2 * N + 1;
	for(int i=1; i <= N; i++)
	{
		addEdge(source, in(i), 1);
		addEdge(out(i), sink, 1);
	}

	for(int i=0; i < M; i++)
	{
		int u, v;
		scanf("%d%d", &u, &v);
		addEdge(in(u), out(v), 1);
	}

	printf("%d", maximumFlow(source, sink));
	return 0;
}