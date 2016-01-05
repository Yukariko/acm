#include <bits/stdc++.h>

using namespace std;

const int INF = 987654321;

vector<vector<pair<int,int>>> a;

void dijkstra(int V, int u, vector<int>& d)
{
	d.resize(V+1);
	fill(d.begin(), d.end(), INF);

	d[u] = 0;

	priority_queue<pair<int, int>> pq;
	pq.push({0, u});

	while(!pq.empty())
	{
		pair<int,int> pick = pq.top();
		pq.pop();

		int v = pick.second;
		int w = -pick.first;

		for(size_t i=0; i < a[v].size(); i++)
		{
			int nw = a[v][i].second;
			int nv = a[v][i].first;
			if(w + nw < d[nv])
			{
				d[nv] = w + nw;
				pq.push({-w - nw, nv});
			}
		}
	}
}

int main()
{
	int N, M, X;
	scanf("%d%d%d",&N,&M,&X);

	a.resize(N+1);

	while(M--)
	{
		int u, v, w;
		scanf("%d%d%d",&u,&v,&w);
		a[u].push_back({v, w});
	}

	vector<int> xtov;
	dijkstra(N, X, xtov);

	int ans = 0;
	for(int i=1; i <= N; i++)
	{
		vector<int> vtox;
		dijkstra(N, i, vtox);
		ans = max(ans, xtov[i] + vtox[X]);
	}

	printf("%d", ans);
	return 0;
}