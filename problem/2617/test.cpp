#include <bits/stdc++.h>

using namespace std;

const int INF = 987654321;

int N, M;

int d[101][101];

int main()
{
	scanf("%d%d", &N, &M);

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
		int passedTo = 0;
		int passedFrom = 0;
		for(int j=1; j <= N; j++)
		{
			if(d[i][j] != INF)
				passedTo++;
			if(d[j][i] != INF)
				passedFrom++;
		}


		if(max(passedTo, passedFrom) > (N+1) / 2)
			ans++;
	}

	printf("%d", ans);
	return 0;
}