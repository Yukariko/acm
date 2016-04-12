#include <bits/stdc++.h>

using namespace std;

const int INF = 987654321;

int N;
int a[2223][2223];
int cache[2223][2223];

int solve(int y, int x)
{
	if(y == N-1 && x == N-1)
		return 0;

	int& ans = cache[y][x];
	if(ans != -1)
		return ans;

	ans = INF;
	if(y < N-1)
		ans = min(ans, (a[y][x] > a[y+1][x]? 0: a[y+1][x] - a[y][x] + 1) + solve(y + 1, x));
	if(x < N-1)
		ans = min(ans, (a[y][x] > a[y][x+1]? 0: a[y][x+1] - a[y][x] + 1) + solve(y, x + 1));

	return ans;
}

int main()
{
	scanf("%d", &N);
	for(int i=0; i < N; i++)
		for(int j=0; j < N; j++)
			scanf("%d", &a[i][j]);

	memset(cache, -1, sizeof(cache));
	printf("%d", solve(0, 0));
	return 0;
}