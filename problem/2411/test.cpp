#include <bits/stdc++.h>

using namespace std;

int N, M;
int A, B;

int a[101][101];
int cache[101][101][201];

int solve(int y, int x, int cnt)
{
	if(y == N || x == M || a[y][x] == 2)
		return 0;
	if(y == N-1 && x == M-1)
		return cnt == 0;

	int& ans = cache[y][x][cnt];
	if(ans != -1)
		return ans;

	if(a[y][x] == 1)
		cnt--;

	ans = solve(y + 1, x, cnt) + solve(y, x + 1, cnt);
	return ans;
}


int main()
{
	scanf("%d%d%d%d", &N, &M, &A, &B);
	for(int i=0; i < A; i++)
	{
		int y, x;
		scanf("%d%d", &y, &x);
		y--; x--;
		a[y][x] = 1;
	}

	for(int i=0; i < B; i++)
	{
		int y, x;
		scanf("%d%d", &y, &x);
		y--; x--;
		a[y][x] = 2;
	}

	memset(cache, -1, sizeof(cache));
	printf("%d", solve(0, 0, A));
	return 0;
}