#include <bits/stdc++.h>

using namespace std;

int a[1024][1024];
int sum[1025][1025];

int main()
{
	int N, M;
	scanf("%d%d", &N, &M);

	for(int i=0; i < N; i++)
		for(int j=0; j < N; j++)
			scanf("%d", &a[i][j]);

	for(int i=1; i <= N; i++)
	{
		sum[i][1] = sum[i-1][1] + a[i-1][0];
		sum[1][i] = sum[1][i-1] + a[0][i-1];
	}

	for(int i=2; i <= N; i++)
		for(int j=2; j <= N; j++)
			sum[i][j] = sum[i][j-1] + sum[i-1][j] - sum[i-1][j-1] + a[i-1][j-1];

	for(int i=0; i < M; i++)
	{
		int y1, x1, y2, x2;
		scanf("%d%d%d%d", &y1, &x1, &y2, &x2);
		printf("%d\n", sum[y2][x2] - sum[y2][x1-1] - sum[y1-1][x2] + sum[y1-1][x1-1]);
	}
	return 0;
}