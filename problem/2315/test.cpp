#include <bits/stdc++.h>

using namespace std;

int N, M;
int D[1001], W[1001];
int sum[1001];

int cache[1001][1001][2];

int solve(int left, int right, bool forceLeft)
{
	if(left == 0 && right == N-1)
		return 0;

	int& ans = cache[left][right][forceLeft];
	if(ans != -1)
		return ans;

	ans = 987654321;

	int start = forceLeft? left : right;

	if(left > 0)
	{
		int diff = D[start] - D[left - 1];
		int waste = (sum[N] - sum[right + 1] + sum[left]) * diff;
		ans = min(ans, waste + solve(left - 1, right, true));
	}

	if(right < N-1)
	{
		int diff = D[right + 1] - D[start];
		int waste = (sum[N] - sum[right + 1] + sum[left]) * diff;
		ans = min(ans, waste + solve(left, right + 1, false));
	}
	return ans;
}

int main()
{
	memset(cache, -1, sizeof(cache));
	scanf("%d%d", &N, &M);
	for(int i=0; i < N; i++)
		scanf("%d%d", &D[i], &W[i]);

	sum[0] = 0;
	for(int i=0; i < N; i++)
		sum[i+1] = sum[i] + W[i];

	printf("%d", solve(M-1, M-1, false));
	return 0;
}