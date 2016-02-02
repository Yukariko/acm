#include <bits/stdc++.h>

using namespace std;

int H, W;

int a[1501][1501];
char b[1501][1501];

int sum[1501][1501][2];

int cache[1501][1501];

int earn(int y, int x)
{
	if(y >= H || x >= W)
		return 0;
	int n = sum[H-1][x][0] - sum[y][x][0];
	if(y > 0)
		n += sum[y-1][x][1];
	return n;
}

int solve(int y, int x)
{
	if(y >= H || x >= W)
		return -987654321;
	if(y == H-1 && x == W-1)
		return 0;

	int& ans = cache[y][x];
	if(ans != -1)
		return ans;

	ans = max(earn(y+1, x+1) + solve(y+1, x+1), earn(y, x+1) + solve(y, x+1));
	if(y < H-1)
	ans = max(ans, (b[y+1][x] == 'A'? -a[y+1][x]: 0) + solve(y+1, x));
	return ans;
}

int main()
{
	memset(cache, -1, sizeof(cache));
	scanf("%d%d", &H, &W);
	for(int i=0; i < H; i++)
		for(int j=0; j < W; j++)
			scanf(" %c%d,", &b[i][j], &a[i][j]);

	for(int i=0; i < W; i++)
		sum[0][i][b[0][i] - 'A'] = a[0][i];

	for(int i=1; i < H; i++)
	{
		for(int j=0; j < W; j++)
		{
			sum[i][j][0] = sum[i-1][j][0];
			sum[i][j][1] = sum[i-1][j][1];
			sum[i][j][b[i][j] - 'A'] += a[i][j];
		}
	}

	printf("%d", sum[H-1][0][0] - sum[0][0][0] + solve(0, 0));
	return 0;
}