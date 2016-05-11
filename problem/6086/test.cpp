#include <bits/stdc++.h>

using namespace std;

const int INF = 987654321;

int V = 127;
int cap[127][127];
int flow[127][127];

void addEdge(int u, int v, int w)
{
	cap[u][v] = max(cap[u][v], w);
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

			for(int there=0; there < V; there++)
			{
				if(cap[here][there] - flow[here][there] > 0 && parent[there] == -1)
				{
					parent[there] = here;
					q.push(there);
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
	int N;
	scanf("%d", &N);

	int source = 'A';
	int sink = 'Z';

	while(N--)
	{
		char u, v;
		int f;
		scanf(" %c %c %d", &u, &v, &f);
		addEdge(u, v, f);
	}

	printf("%d", maximumFlow(source, sink));
	return 0;
}