#include <bits/stdc++.h>

using namespace std;

int main()
{
	int T;
	scanf("%d",&T);

	int div[] = {1, 10, 25};

	while(T--)
	{
		long long N;
		scanf("%lld",&N);

		long long ans = 0;
		while(N)
		{
			int dp[101];
			dp[0] = 0;
			for(int i=1; i <= 100; i++)
				dp[i] = 987654321;

			for(int i=0; i < 3; i++)
				for(int j=div[i]; j <= N % 100; j++)
					dp[j] = min(dp[j], dp[j-div[i]] + 1);
				
			ans += dp[N % 100];
			N /= 100;
		}
		printf("%lld\n", ans);
	}
	return 0;
}