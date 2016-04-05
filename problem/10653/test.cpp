#include <bits/stdc++.h>

using namespace std;

int N, K;
int y[501];
int x[501];

int cache[502][502];

int solve(int pos, int cnt)
{
	if(pos == N-1)
		return 0;

	int& ans = cache[pos][cnt];
	if(ans != -1)
		return ans;

	ans = 987654321;
	for(int i=0; i <= cnt && pos + i + 1 < N; i++)
		ans = min(ans, abs(y[pos] - y[pos+i+1]) + abs(x[pos] - x[pos+i+1]) + solve(pos + i + 1, cnt - i));
	return ans;
}

int main()
{
	memset(cache, -1, sizeof(cache));
	scanf("%d%d", &N, &K);
	for(int i=0; i < N; i++)
		scanf("%d%d", &x[i], &y[i]);
	printf("%d", solve(0, K));
	return 0;
}