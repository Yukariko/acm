#include <iostream>
#include <algorithm>
#include <cstring>
#include <vector>
#include <cstdio>
#include <map>

using namespace std;

const int MOD = 1000000009;

const char *error1 = "ABCBC";
const char *error2 = "ABABC";

const int jump1[5][3] = {
	{1,0,0},
	{1,2,0},
	{1,0,3},
	{1,4,0},
	{1,0,5}
};

const int jump2[5][3] = {
	{1,0,0},
	{1,2,0},
	{3,0,0},
	{1,4,0},
	{3,0,5}
};

int N, K;
int cache[1000001][6][6];
int solve(int pos, int match1, int match2)
{
	if(match1 == 5 || match2 == 5)
		return 0;

	if(pos == N)
		return 1;

	int& ret = cache[pos][match1][match2];
	if(ret != -1)
		return ret;

	ret = 0;
	for(int i=0; i < 3; i++)
		ret = ((long long)ret + solve(pos+1, jump1[match1][i], jump2[match2][i])) % MOD;
	ret = ((long long)ret + (long long)(K-3) * solve(pos+1, 0, 0)) % MOD;
	return ret;
}

int main()
{
	memset(cache, -1, sizeof(cache));
	scanf("%d%d",&N,&K);
	printf("%d",solve(0,0,0));
	return 0;
}