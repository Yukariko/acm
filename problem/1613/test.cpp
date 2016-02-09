#include <bits/stdc++.h>

using namespace std;

const int INF = 987654321;

int main()
{
	int N, M;
	scanf("%d%d", &N, &M);

	int d[401][401];
	for(int i=1; i <= N; i++)
	{
		for(int j=1; j <= N; j++)
			d[i][j] = INF;
		d[i][i] = 0;
	}

	for(int i=0; i < M; i++)
	{
		int u, v;
		scanf("%d%d", &u, &v);
		d[u][v] = 1;
	}

	for(int k=1; k <= N; k++)
		for(int i=1; i <= N; i++)
			for(int j=1; j <= N; j++)
				d[i][j] = min(d[i][j], d[i][k] + d[k][j]);

	int T;
	scanf("%d", &T);

	while(T--)
	{
		int u, v;
		scanf("%d%d", &u, &v);

		if(d[u][v] == INF && d[v][u] == INF)
			puts("0");
		else if(d[u][v] != INF)
			puts("-1");
		else
			puts("1");
	}
	return 0;
}