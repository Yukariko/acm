#include <bits/stdc++.h>

using namespace std;

const int INF = 987654321;

int main()
{
	int N;
	scanf("%d",&N);

	int d[101][101];
	for(int i=0; i < N; i++)
	{
		for(int j=0; j < N; j++)
		{
			scanf("%d",&d[i][j]);
			if(d[i][j] == 0)
				d[i][j] = INF;
		}
	}

	for(int k=0; k < N; k++)
		for(int i=0; i < N; i++)
			for(int j=0; j < N; j++)
				d[i][j] = min(d[i][j], d[i][k] + d[k][j]);

	for(int i=0; i < N; i++)
	{
		for(int j=0; j < N; j++)
			printf("%d ", d[i][j] != INF);
		puts("");
	}
	return 0;
}