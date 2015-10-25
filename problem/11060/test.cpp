#include <bits/stdc++.h>

using namespace std;

const int INF = 987654321;

int N;
int a[1001];
int cache[1001];

int solve(int pos)
{
	if(pos == N-1)
		return 0;

	int& ret = cache[pos];
	if(ret != -1)
		return ret;

	ret = INF;
	for(int i=1, e = min(a[pos], N-1); i <= e; i++)
		ret = min(ret, 1 + solve(pos + i));
	return ret;
}

int main()
{
	memset(cache, -1, sizeof(cache));
	scanf("%d",&N);
	for(int i=0; i < N; i++)
		scanf("%d",&a[i]);
	int ans = solve(0);
	printf("%d",ans == INF? -1: ans);
	return 0;
}