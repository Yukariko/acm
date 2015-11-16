#include <bits/stdc++.h>

using namespace std;

int N, M, K;
int cache[31];

int solve(int pos)
{
	if(pos == 0)
		return 1;

	int& ans = cache[pos];
	if(ans != -1)
		return ans;

	ans = 0;
	for(int i=1; i <= pos; i+=1)
		if((i - M) % K != 0)
			ans += solve(pos - i);
	return ans;
}

int main()
{
	int T;
	scanf("%d",&T);

	while(T--)
	{
		int tc;
		scanf("%d%d%d%d",&tc,&N,&M,&K);
		memset(cache, -1, sizeof(cache));
		printf("%d %d\n", tc, solve(N));
	}
	return 0;
}