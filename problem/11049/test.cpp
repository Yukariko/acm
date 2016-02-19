#include <bits/stdc++.h>

using namespace std;

int N;
int a[501][2];

int cache[501][501];

int solve(int left, int right)
{
	if(left >= right)
		return 0;

	int& ans = cache[left][right];
	if(ans != -1)
		return ans;

	ans = 987654321;
	for(int i=left; i < right; i++)
		ans = min(ans, a[left][0] * a[i][1] * a[right][1] + solve(left, i) + solve(i+1, right));

	return ans;
}

int main()
{
	scanf("%d", &N);
	int n;
	for(int i=0; i < N; i++)
		scanf("%d%d", &a[i][0], &a[i][1]);

	memset(cache, -1, sizeof(cache));

	printf("%d", solve(0, N-1));
	return 0;
}