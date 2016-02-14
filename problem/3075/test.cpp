// floyd

#include <bits/stdc++.h>

using namespace std;

const int INF = 987654321;

int main()
{
	int T;
	scanf("%d", &T);

	while(T--)
	{
		int N, V, E;
		scanf("%d%d%d", &N, &V, &E);

		vector<int> a(N);
		for(int i=0; i < N; i++)
			scanf("%d", &a[i]);

		int d[101][101];
		for(int i=1; i <= V; i++)
		{
			for(int j=1; j <= V; j++)
				d[i][j] = INF;
			d[i][i] = 0;
		}

		while(E--)
		{
			int u, v, w;
			scanf("%d%d%d", &u, &v, &w);
			d[u][v] = d[v][u] = w;
		}

		for(int k=1; k <= V; k++)
			for(int i=1; i <= V; i++)
				for(int j=1; j <= V; j++)
					d[i][j] = min(d[i][j], d[i][k] + d[k][j]);

		int ans = -1;
		int maxcost = INF;

		for(int i=1; i <= V; i++)
		{
			int cost = 0;
			for(int j=0; j < N; j++)
				cost += d[i][a[j]] * d[i][a[j]];
			if(maxcost > cost)
			{
				maxcost = cost;
				ans = i;
			}
		}

		printf("%d %d\n", ans, maxcost);
	}
	return 0;
}