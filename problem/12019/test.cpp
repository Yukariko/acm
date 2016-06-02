#include <bits/stdc++.h>

using namespace std;

int N, M;
int a[101];

int cache[101][11][2001];

int solve(int pos, int cnt, int sum)
{
	if(pos == N)
		return 0;

	int& ans = cache[pos][cnt][sum];
	if(ans != -1)
		return ans;

	ans = sum * a[pos] + solve(pos + 1, cnt, sum + a[pos]);
	if(cnt)
		ans = min(ans, sum * a[pos] + solve(pos + 1, cnt - 1, 0));

	return ans;
}

void construct(int pos, int cnt, int sum)
{
	if(pos == N)
		return;

	if(cnt && cache[pos + 1][cnt][sum + a[pos]] >= cache[pos + 1][cnt - 1][0])
	{
		printf("%d ", pos + 1);
		return construct(pos + 1, cnt - 1, 0);
	}
	return construct(pos + 1, cnt, sum + a[pos]);
}

int main()
{
	scanf("%d%d", &N, &M);
	for(int i=0; i < N; i++)
		scanf("%d", &a[i]);

	memset(cache, -1, sizeof(cache));
	printf("%d\n", solve(0, M, 0));
	construct(0, M, 0);
	return 0;
}