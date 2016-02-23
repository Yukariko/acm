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

	~NetworkFlow()
	{
		for(int i=0; i < V; i++)
			for(size_t j=0; j < adj[i].size(); j++)
				delete adj[i][j];
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

	void pop(int u, int v)
	{
		adj[u].pop_back();
		adj[v].pop_back();
	}

	void clear()
	{
		for(int i=0; i < V; i++)
			for(size_t j=0; j < adj[i].size(); j++)
				adj[i][j]->flow = 0;
	}

private:
	int V;
	vector<vector<Edge *>> adj;

};

bool isPrime(int N)
{
	for(int i=2; i * i <= N; i++)
		if(N % i == 0)
			return false;
	return true;
}

int tok;

int in(int v)
{
	return v;
}

int out(int v)
{
	return tok + v;
}

int main()
{
	int N;
	scanf("%d", &N);

	vector<int> a(N);
	for(int i=0; i < N; i++)
		scanf("%d", &a[i]);

	NetworkFlow nf(N * 2 + 2);
	tok = N;
	int source = N * 2;
	int sink = N * 2 + 1;

	for(int i=0; i < N; i++)
	{
		nf.addEdge(source, in(i), 1);
		nf.addEdge(out(i), sink, 1);
	}

	for(int i=1; i < N; i++)
	{
		for(int j=i+1; j < N; j++)
		{
			if(isPrime(a[i] + a[j]))
			{
				nf.addEdge(in(i), out(j), 1);
				nf.addEdge(in(j), out(i), 1);
			}
		}	
	}

	vector<int> ans;
	for(size_t i=1; i < N; i++)
	{
		if(isPrime(a[0] + a[i]))
		{
			nf.addEdge(in(0), out(i), 1);
			nf.addEdge(in(i), out(0), 1);

			int grouping = nf.getMaximumFlow(source, sink);
			if(grouping == N)
				ans.push_back(a[i]);

			nf.pop(in(0), out(i));
			nf.pop(in(i), out(0));
			nf.clear();
		}
	}

	if(ans.empty())
	{
		puts("-1");
		return 0;
	}

	sort(ans.begin(), ans.end());
	for(auto &n : ans)
		printf("%d ", n);
	return 0;
}