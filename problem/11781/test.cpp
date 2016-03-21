#include <bits/stdc++.h>

using namespace std;

int N, M;
int S, E;

bool lated[5001][5001];
int distances[5001][5001];

vector<int> adj[5001];

double dijkstra()
{
	vector<double> dist(N+1, 1e20);
 	dist[1] = 0;

	priority_queue<pair<double, int>> pq;
	pq.push({0, 1});
	
	while(!pq.empty())
	{
		double cost = -pq.top().first;
		int here = pq.top().second;
		pq.pop();

		if(dist[here] < cost)
			continue;

		for(size_t i=0; i < adj[here].size(); i++)
		{
			int there = adj[here][i];
			double d = distances[here][there];
			
			if(!lated[here][there] || (cost + d < S || E < cost))
				d = cost + d;
			else if(S <= cost && cost + d * 2 <= E)
				d = cost + d * 2;
			else if(cost < S)
			{
				if(d - (S - cost) < (E - S) / 2.0)
					d = S + (d - (S - cost)) * 2;
				else
					d = E + (d - (S - cost) - (E - S) / 2.0);
			}
			else
				d = E + (d - (E - cost) / 2.0);

			if(dist[there] > d)
			{
				dist[there] = d;
				pq.push({-d, there});
			}
		}
	}

	double ans = 0;
	for(int i=1; i <= N; i++)
		ans = max(ans, min({dist[i], dist[i], dist[i]}));
	return ans;
}

int main()
{
	scanf("%d%d%d%d", &N, &M, &S, &E);
	for(int i=0; i < M; i++)
	{
		int u, v, w, t1, t2;
		scanf("%d%d%d%d%d", &u, &v, &w, &t1, &t2);
		adj[u].push_back(v);
		adj[v].push_back(u);
		distances[u][v] = distances[v][u] = w;

		if(t1)
			lated[u][v] = true;
		if(t2)
			lated[v][u] = true;
	}

	cout << setprecision(14) << dijkstra();
	return 0;
}