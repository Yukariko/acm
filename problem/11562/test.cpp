#include <bits/stdc++.h>

using namespace std;

const int INF = 987654321;

int d[251][251];

int main()
{
	int N, M;
	scanf("%d%d", &N, &M);

	for(int i=1; i <= N; i++)
		for(int j=1; j <= N; j++)
			d[i][j] = i == j? 0: INF;

	for(int i=0; i < M; i++)
	{
		int u, v, w;
		scanf("%d%d%d", &u, &v, &w);
		if(w == 0)
			d[u][v] = 0, d[v][u] = 1;
		else
			d[u][v] = d[v][u] = 0;
	}

	for(int k=1; k <= N; k++)
		for(int i=1; i <= N; i++)
			if(d[i][k] != INF)
				for(int j=1; j <= N; j++)
					d[i][j] = min(d[i][j], d[i][k] + d[k][j]);

	int K;
	scanf("%d", &K);

	while(K--)
	{
		int u, v;
		scanf("%d%d", &u, &v);
		printf("%d\n", d[u][v]);
	}
	return 0;
}