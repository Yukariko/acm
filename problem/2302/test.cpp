#include <bits/stdc++.h>

using namespace std;

int N, M;
bool a[41];

int cache[41][2];

int solve(int pos, bool move)
{
	if(pos == N)
		return !move;

	int& ret = cache[pos][move];
	if(ret)
		return ret;

	if(a[pos])
	{
		if(move)
			return 0;
		return ret = solve(pos+1, false);
	}
	if(move)
		return ret = solve(pos+1, false);
	return ret = solve(pos+1, true) + solve(pos+1, false);
}

int main()
{
	scanf("%d%d",&N,&M);

	for(int i=0; i < M; i++)
	{
		int n;
		scanf("%d",&n);
		a[n-1] = true;
	}
	printf("%d",solve(0,false));
	return 0;
}