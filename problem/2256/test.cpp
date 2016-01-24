#include <bits/stdc++.h>

using namespace std;

int N, K;
int a[5001];
int cache[5001][1001];

int score(int p, int q)
{
	return (p - q) * (p - q);
}

int solve(int pos, int cnt)
{
	if(cnt == K)
		return 0;
	if(pos == N)
		return 1087654321;

	int& ans = cache[pos][cnt];
	if(ans != -1)
		return ans;

	ans = solve(pos + 1, cnt);
	if(pos < N-1 && cnt * 3 < pos)
		ans = min(ans, score(a[pos], a[pos+1]) + solve(pos + 2, cnt + 1));
	return ans;
}

int main()
{
	memset(cache, -1, sizeof(cache));

	scanf("%d%d", &K, &N);
	for(int i=0; i < N; i++)
		scanf("%d", &a[i]);

	sort(a, a + N, greater<int>());

	printf("%d", solve(0, 0));
	return 0;
}