#include <iostream>
#include <algorithm>
#include <cstring>

using namespace std;

int N;
int a[2001];
int b[2001];
int dp[2001][2001];

int solve(int aPos, int bPos)
{
	if(aPos == N || bPos == N)
		return 0;

	int &ret = dp[aPos][bPos];
	if(ret != -1)
		return ret;

	if(a[aPos] > b[bPos])
		ret = b[bPos] + solve(aPos, bPos+1);
	else
		ret = max(solve(aPos+1,bPos), solve(aPos+1,bPos+1));
	
	return ret;
}

int main()
{
	memset(dp,-1,sizeof(dp));
	cin >> N;
	for(int i=0; i < N; i++)
		cin >> a[i];
	for(int i=0; i < N; i++)
		cin >> b[i];

	cout << solve(0,0);
	return 0;
}