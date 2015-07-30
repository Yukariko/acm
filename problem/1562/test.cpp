#include <iostream>
#include <cstring>

using namespace std;

const int MOD = 1000000000;

int N;
int dp[101][10][1<<10];

int solve(int pos, int d, int mask)
{
	if(pos == N)
		return mask == (1<<10) - 1;

	int &ret = dp[pos][d][mask];
	if(ret != -1)
		return ret;

	ret = 0;
	if(d + 1 < 10)
		ret += solve(pos+1, d+1, mask | (1 << (d+1)));
	if(d - 1 >= 0)
		ret += solve(pos+1, d-1, mask | (1 << (d-1)));
	
	ret %= MOD;

	return ret;
}

int main()
{
	memset(dp,-1,sizeof(dp));
	cin >> N;

	int ans = 0;
	for(int i=1; i < 10; i++)
	{
		ans += solve(1, i, 1<<i);
		ans %= MOD;
	}

	cout << ans;
	return 0;
}