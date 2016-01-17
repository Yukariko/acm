#include <bits/stdc++.h>

using namespace std;

int main()
{
	int N, M;
	scanf("%d%d", &N, &M);

	int d[101][101];
	for(int i=1; i <= N; i++)
	{
		for(int j=1; j <= N; j++)
			d[i][j] = 654321;
		d[i][i] = 0;
	}

	for(int i=0; i < M; i++)
	{
		int u, v;
		scanf("%d%d", &u, &v);
		d[u][v] = d[v][u] = 1;
	}

	for(int k=1; k <= N; k++)
		for(int i=1; i <= N; i++)
			for(int j=1; j <= N; j++)
				d[i][j] = min(d[i][j], d[i][k] + d[k][j]);

	int ans = 0;
	int sum = 654321;
	for(int i=1; i <= N; i++)
	{
		int count = 0;
		for(int j=1; j <= N; j++)
			count += d[i][j];
		if(sum > count)
		{
			sum = count;
			ans = i;
		}
	}

	printf("%d", ans);
	return 0;
}