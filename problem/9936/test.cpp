#include <bits/stdc++.h>

using namespace std;

const int INF = 987654321;

int N, K;
int a[1001][3];
int cache[1001][1001][8];

bool get(int mask, int pos)
{
	return mask & (1 << pos);
}

int solve(int pos, int cnt, int mask)
{
	if(pos == N)
		return cnt? -INF+1: 0;

	int& ans = cache[pos][cnt][mask];
	if(ans != -INF)
		return ans;

	for(int nmask=0; nmask < 8; nmask++)
	{
		if(mask & nmask)
			continue;

		int sum = 0;
		for(int i=0; i < 3; i++)
			if(get(nmask, i))
				sum += a[pos][i] + a[pos-1][i];

		int use = __builtin_popcount(nmask);

		ans = max(ans, sum + solve(pos + 1, cnt - use, nmask));
		for(int j=0; j < 2; j++)
			if(!get(nmask, j) && !get(nmask, j+1))
				ans = max(ans, sum + a[pos][j] + a[pos][j+1] + solve(pos + 1, cnt - use - 1, nmask | (3 << j)));
	}

	return ans;
}

int main()
{
	scanf("%d%d", &N, &K);
	for(int i=0; i < N; i++)
		scanf("%d%d%d", &a[i][0], &a[i][1], &a[i][2]);

	fill(&cache[0][0][0], &cache[1001][0][0], -INF);
	printf("%d", solve(0, K, 7));
	return 0;
}