#include <bits/stdc++.h>

using namespace std;

int N;
int a[1001];
int cache[1001][1001];

int solve(int pos, int cnt)
{
	if(pos == N+1)
		return 0;

	int& ret = cache[pos][cnt];
	if(ret != -1)
		return ret;

	ret = solve(pos+1, cnt);
	for(int i=pos; i <= cnt; i+=pos)
		ret = max(ret, a[pos] * (i / pos) + solve(pos+1, cnt - i));
	return ret;
}


int main()
{
	scanf("%d",&N);
	for(int i=1; i <= N; i++)
		scanf("%d",&a[i]);

	memset(cache, -1, sizeof(cache));
	printf("%d",solve(1, N));
	return 0;
}