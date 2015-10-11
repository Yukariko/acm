#include <bits/stdc++.h>

using namespace std;

int N, K;

int cache[101][101][2];

int solve(int pos, int k, int last)
{
	if(pos == N)
		return k == K;

	int& ans = cache[pos][k][last];
	if(ans != -1)
		return ans;

	ans = solve(pos+1, last? k+1 : k, 1);
	ans += solve(pos+1, k, 0);
	return ans;
}
int main()
{
	int T;
	scanf("%d",&T);

	while(T--)
	{
		scanf("%d%d",&N,&K);
		memset(cache, -1, sizeof(cache));

		// 0 0
		int ans = solve(2, 0, 0);
		// 1 0
		ans += solve(2, 0, 0);
		// 0 1
		ans += solve(2, 0, 1);
		// 1 1
		ans += solve(2, 1, 1);
		printf("%d\n",ans);
	}
	return 0;
}