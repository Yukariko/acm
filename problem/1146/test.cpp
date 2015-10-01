#include <bits/stdc++.h>

using namespace std;

const int MOD = 1000000;

int N;
int cache[101][101][2];

int solve(int left, int right, bool lr)
{
	if(left == 0 && right == 0)
		return 1;

	int& ret = cache[left][right][lr];
	if(ret)
		return ret;

	if(lr == false)
		for(int i=1; i <= right; i++)
			ret = (ret + solve(left + i - 1, right - i, true)) % MOD;
	else
		for(int i=1; i <= left; i++)
			ret = (ret + solve(left - i, right + i - 1, false)) % MOD;
	return ret;
}

int main()
{
	scanf("%d",&N);

	if(N == 1)
	{
		printf("1");
		return 0;
	}

	int ans = 0;
	for(int i=1; i <= N; i++)
		for(int j=1; j <= N; j++)
			if(i != j)
				if(i > j)
					ans = (ans + solve(j-1,N-j-1,false)) % MOD;
				else
					ans = (ans + solve(j-1-1,N-j,true)) % MOD;
	printf("%d",ans);
	return 0;
}