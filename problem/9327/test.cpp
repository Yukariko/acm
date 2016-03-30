#include <bits/stdc++.h>

using namespace std;

int N, E;
int a[101];
int cache[101][200001];

int solve(int pos, int sum)
{
	if(sum * 2 >= E)
		return 0;
	if(pos == N)
		return 987654321;

	int& ans = cache[pos][sum];
	if(ans != -1)
		return ans;

	ans = solve(pos + 1, sum);
	ans = min(ans, a[pos] + solve(pos + 1, sum + a[pos]));
	return ans;
}

int main()
{
	int T;
	scanf("%d", &T);

	while(T--)
	{
		scanf("%d%d", &N, &E);
		int sum = 0;
		for(int i=0; i < N; i++)
		{
			scanf("%d", &a[i]);
			sum += a[i];
		}

		if(sum * 2 < E)
			puts("FULL");
		else
		{
			memset(cache, -1, sizeof(cache));
			printf("%d\n", solve(0, 0));
		}
	}
	return 0;
}