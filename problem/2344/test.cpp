#include <bits/stdc++.h>

using namespace std;

int N, M;
int a[1001][1001];

int solve(int y, int x)
{
	int dy = y == 0? 1: y == N+1? -1: 0;
	int dx = x == 0? 1: x == M+1? -1: 0;

	while(true)
	{
		y += dy;
		x += dx;
		if(y == 0 || y == N+1 || x == 0 || x == M+1)
			break;

		if(a[y][x] == 1)
		{
			int t = dy;
			dy = -dx;
			dx = -t;
		}
	}

	if(x == 0)
		return y;
	if(y == N+1)
		return N + x;
	if(x == M+1)
		return N + M + (N - y + 1);
	return N + M + N + (M - x + 1);
}


int main()
{
	scanf("%d%d",&N,&M);
	for(int i=1; i <= N; i++)
		for(int j=1; j <= M; j++)
			scanf("%d",&a[i][j]);

	for(int i=1; i <= N; i++)
		printf("%d ", solve(i, 0));
	for(int i=1; i <= M; i++)
		printf("%d ", solve(N+1, i));
	for(int i=N; i >= 1; i--)
		printf("%d ", solve(i, M+1));
	for(int i=M; i >= 1; i--)
		printf("%d ", solve(0, i));
	return 0;
}