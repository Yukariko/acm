#include <bits/stdc++.h>

using namespace std;

const int MOD = 10007;

int cache[1001][10];
int N;

int solve(int pos, int last)
{
	if(pos == N)
		return 1;

	int& ret = cache[pos][last];
	if(ret != -1)
		return ret;

	ret = 0;
	for(int i=last; i <= 9; i++)
		ret = (ret + solve(pos+1, i)) % MOD;
	return ret;
}

int main()
{
	memset(cache, -1, sizeof(cache));
	scanf("%d",&N);
	printf("%d", solve(0,0));
	return 0;
}