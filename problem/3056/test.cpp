#include <bits/stdc++.h>

using namespace std;

int N;
int a[21][21];

double cache[1<<20];

double solve(int here, int mask)
{
	if(here == N)
		return 1;

	double& ans = cache[mask];
	if(ans != -1)
		return ans;

	ans = 0;
	for(int i=0; i < N; i++)
	{
		if(mask & (1 << i))
			continue;
		ans = max(ans, solve(here + 1, mask | (1 << i)) * a[here][i] / 100);
	}
	return ans;
}

int main()
{
	fill(&cache[0], &cache[1<<20], -1);
	scanf("%d", &N);
	for(int i=0; i < N; i++)
		for(int j=0; j < N; j++)
			scanf("%d", &a[i][j]);

	printf("%f", solve(0, 0) * 100);
	return 0;
}