#include <bits/stdc++.h>

using namespace std;

const int INF = 987654321;

int main()
{
	int V, E;
	scanf("%d%d", &V, &E);

	int d[401][401];
	for(int i=1; i <= V; i++)
	{
		for(int j=1; j <= V; j++)
			d[i][j] = INF;
		d[i][i] = 0;
	}

	for(int i=0; i < E; i++)
	{
		int u, v, w;
		scanf("%d%d%d", &u, &v, &w);
		d[u][v] = w;
	}

	for(int k=1; k <= V; k++)
		for(int i=1; i <= V; i++)
			for(int j=1; j <= V; j++)
				d[i][j] = min(d[i][j], d[i][k] + d[k][j]);

	int ans = INF;
	for(int i=1; i <= V; i++)
		for(int j=1; j <= V; j++)	
			if(i != j)
				ans = min(ans, d[i][j] + d[j][i]);
	printf("%d", ans == INF? -1: ans);
	return 0;
}