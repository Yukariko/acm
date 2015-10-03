#include <bits/stdc++.h>

using namespace std;

int N;
int a[501];
int cache[501][501];
int sum[501];

int get_sum(int left, int right)
{
	return sum[right+1] - sum[left];
}

int solve(int left, int right)
{
	if(left + 1 == right)
		return get_sum(left, right);
	if(left == right)
		return 0;

	int& ret = cache[left][right];
	if(ret != -1)
		return ret;

	ret = INT_MAX;
	for(int i=left; i < right; i++)
		ret = min(ret, solve(left, i) + solve(i+1, right) + get_sum(left, right));

	return ret;
}

int main()
{
	int T;
	scanf("%d",&T);

	while(T--)
	{
		scanf("%d",&N);
		for(int i=0; i < N; i++)
			scanf("%d",&a[i]);

		memset(cache, -1, sizeof(cache));

		sum[0] = 0;
		for(int i=1; i <= N; i++)
			sum[i] = sum[i-1] + a[i-1];

		printf("%d\n", solve(0, N-1));
	}
	return 0;
}