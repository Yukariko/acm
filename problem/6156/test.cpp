#include <bits/stdc++.h>

using namespace std;

const int INF = 987654321;

int main()
{
	int N, M;
	scanf("%d%d", &N, &M);

	int d[101][101];
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

	int ans = 0;
	for(int i=1; i <= N; i++)
	{
		int know = 0;
		for(int j=1; j <= N; j++)
			if(d[i][j] != INF || d[j][i] != INF)
				know++;
		if(know == N)
			ans++;
	}

	printf("%d", ans);
	return 0;
}