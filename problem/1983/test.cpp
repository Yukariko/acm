#include <bits/stdc++.h>

using namespace std;

const int INF = 987654321;

int N;
int aN, bN;
int aJ, bJ;
int a[401], b[401];
int cache[401][401][401];

int solve(int pos, int ajump, int bjump)
{
	if(ajump > bJ || bjump > aJ)
		return -INF+1;

	int apos = pos + ajump;
	int bpos = pos + bjump;

	if(apos == N && bpos == N)
		return 0;

	if(apos == N || bpos == N)
		return -INF+1;

	int& ans = cache[pos][ajump][bjump];
	if(ans != -INF)
		return ans;

	ans = a[apos] * b[bpos] + solve(pos+1, ajump, bjump);
	ans = max(ans, solve(pos, ajump+1, bjump));
	ans = max(ans, solve(pos, ajump, bjump+1));
	return ans;
}

int main()
{
	fill(&cache[0][0][0], &cache[401][0][0], -INF);
	scanf("%d", &N);
	for(int i=0; i < N; i++)
	{
		scanf("%d", &a[aN]);
		if(a[aN] != 0)
			aN++;
		else
			aJ++;
	}
	for(int i=0; i < N; i++)
	{
		scanf("%d", &b[bN]);
		if(b[bN] != 0)
			bN++;
		else
			bJ++;
	}

	printf("%d", solve(0, 0, 0));
	return 0;
}