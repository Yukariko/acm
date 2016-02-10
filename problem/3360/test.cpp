#include <bits/stdc++.h>

using namespace std;

const int MOD = 1000000;

int main()
{
	int N;
	scanf("%d",  &N);

	int ans = 0;
	int sum = 1;
	int i = 0;
	for(; i + 6 <= N; i+=6)
	{
		ans = (ans + 6 * sum) % MOD;
		sum++;
	}

	ans = (ans + (N - i) * sum) % MOD;
	if(N - i == 0)
		ans = (ans + 1) % MOD;
	else if(N - i == 1)
		ans = (ans + MOD - 1) % MOD;

	printf("%d", ans);
	return 0;
}