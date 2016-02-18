#include <bits/stdc++.h>

using namespace std;

const int INF = 987654321;

class NetworkFlow
{
public:
	struct Edge 
	{
		int target, capacity, flow;
		Edge *reverse;

		int residualCapacity() const { return capacity - flow; }

		void push(int amt)
		{
			flow += amt;
			reverse->flow -= amt;
		}
	};

	NetworkFlow(int V) : V(V)
	{
		adj.resize(V);
	}

	void addEdge(int u, int v, int capacity)
	{
		Edge *uv = new Edge(), *vu = new Edge();

		uv->target = u;
		uv->capacity = capacity;
		uv->flow = 0;
		uv->reverse = vu;

		vu->target = v;
		vu->capacity = 0;
		vu->flow = 0;
		vu->reverse = uv;

		adj[u].push_back(uv);
		adj[v].push_back(vu);
	}

	int getMaximumFlow(int source, int sink)
	{
		int totalFlow = 0;

		while(true)
		{
			vector<pair<int, Edge*>> parent(V, {-1, nullptr});

			queue<int> q;
			parent[source].first = source;
			q.push(source);

			while(!q.empty() && parent[sink].first == -1)
			{
				int here = q.front();
				q.pop();

				for(size_t i=0; i < adj[here].size(); i++)
				{
					Edge *there = adj[here][i];
					int v = there->reverse->target;

					if(there->residualCapacity() > 0 && parent[v].first == -1)
					{
						q.push(v);
						parent[v] = {here, there};
					}
				}
			}

			if(parent[sink].first == -1)
				break;

			int amount = INF;
			for(int p = sink; p != source; p = parent[p].first)
				amount = min(amount, parent[p].second->residualCapacity());

			totalFlow += amount;
			for(int p = sink; p != source; p = parent[p].first)
			{
				Edge *uv = parent[p].second;
				uv->push(amount);
			}

		}

		return totalFlow;
	}

private:
	int V;
	vector<vector<Edge *>> adj;

};


int main()
{
	int N, M;
	scanf("%d%d", &N, &M);

	NetworkFlow nf(N+M+2);

	int source = 0;
	int sink = N+M+1;

	for(int i=1; i <= N; i++)
		nf.addEdge(source, i, 1);

	for(int i=1; i <= M; i++)
		nf.addEdge(i + N, sink, 1);

	for(int i=1; i <= N; i++)
	{
		int L;
		scanf("%d", &L);

		int u = i;
		for(int j=0; j < L; j++)
		{
			int v;
			scanf("%d", &v);
			v += N;

			nf.addEdge(u, v, 1);
		}
	}

	printf("%d", nf.getMaximumFlow(source, sink));
	return 0;
}