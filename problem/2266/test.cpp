#include <bits/stdc++.h>

using namespace std;

const int INF = 987654321;

int N, K;
int cache[501][501];
int solve(int range, int cnt)
{
	if(range < 0)
		return 0;

	if(range == 0)
		return cnt? 1: INF;

	if(cnt == 0)
		return INF;

	int& ret = cache[range][cnt];
	if(ret != -1)
		return ret;

	ret = INF;
	for(int i=0; i < range; i++)
	{
		int l = 1 + solve(i-1, cnt-1);
		int r = 1 + solve(range-i-1, cnt);
		
		if(l >= INF || r >= INF)
			continue;
		ret = min(ret, max(l,r));
	}
	return ret;
}

int main()
{
	scanf("%d%d",&N,&K);
	memset(cache, -1, sizeof(cache));
	printf("%d",solve(N-1, K));
	return 0;
}