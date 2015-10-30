#include <bits/stdc++.h>

using namespace std;

int N;
int a[1001];
int cache[1001][1001];

int solve(int pos, int last)
{
	if(pos == N)
		return 0;

	int& ret = cache[pos][last];
	if(ret != -1)
		return ret;

	ret = 0;
	if(last < a[pos])
		ret = max(ret, a[pos] + solve(pos+1, a[pos]));
	ret = max(ret, solve(pos+1, last));
	return ret;
}

int main()
{
	memset(cache, -1, sizeof(cache));
	scanf("%d",&N);
	for(int i=0; i < N; i++)
		scanf("%d",&a[i]);

	printf("%d",solve(0,0));
	return 0;
}