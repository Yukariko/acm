#include <bits/stdc++.h>

using namespace std;

const int INF = 987654321;

int N;
int a[1501][1501];
int cache[1501][1501];

int solve(int lpos, int rpos)
{
	int pos = min(lpos, rpos)-1;
	if(pos == 0)
		return a[lpos][pos] + a[pos][rpos];

	int& ans = cache[lpos][rpos];
	if(ans != -1)
		return ans;

	ans = a[lpos][pos] + solve(pos, rpos);
	ans = min(ans, a[pos][rpos] + solve(lpos, pos));
	return ans;
}

int main()
{
	memset(cache, -1, sizeof(cache));
	scanf("%d", &N);
	for(int i=0; i < N; i++)
		for(int j=0; j < N; j++)
			scanf("%d", &a[i][j]);

	printf("%d", solve(N, N));
	return 0;
}