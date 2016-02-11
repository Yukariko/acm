#include <bits/stdc++.h>

using namespace std;

int N;
long long cache[6][6][11][11][11][11][11];

int sum;

long long solve(int pos, int b1, int b2, int *arr)
{
	if(pos == sum)
		return 1;

	long long& ans = cache[b1][b2][arr[0]][arr[1]][arr[2]][arr[3]][arr[4]];
	if(ans != -1)
		return ans;

	int next_arr[5];
	memcpy(next_arr, arr, sizeof(int) * 5);

	ans = 0;
	for(int i=0; i < N; i++)
	{
		if(arr[i] && b1 != i+1 && b2 != i+1)
		{
			next_arr[i]--;
			ans += solve(pos + 1, i+1, b1, next_arr);
			next_arr[i]++;
		}
	}

	return ans;
}

int main()
{
	memset(cache, -1, sizeof(cache));
	scanf("%d", &N);

	int a[5] = {};
	for(int i=0; i < N; i++)
	{
		scanf("%d", &a[i]);
		sum += a[i];
	}

	printf("%lld", solve(0, 0, 0, a));
	return 0;
}