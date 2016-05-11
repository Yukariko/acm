#include <bits/stdc++.h>

using namespace std;

int cache[202];
int digitLen(int n)
{
	if(n == 0)
		return 0;

	int& ans = cache[n];
	if(ans)
		return ans;
	
	while(n)
	{
		ans++;
		n /= 10;
	}
	return ans;
}

int main()
{
	char a[202];
	scanf("%s", a);
	int N = strlen(a);

	int count[202][202];
	for(int i=0; i < N; i++)
	{
		for(int j=1; j <= i; j++)
		{
			count[i][j] = 1;
			for(int k=i-j, l=0; k >= 0; k--, l++)
			{
				if(a[k] != a[i - (l % j)])
					break;
				if(l % j == j - 1)
					count[i][j]++;
			}
		}
	}

	int dp[202][202];
	for(int i=0; i < N; i++)
	{
		dp[i][i] = 1;
		for(int j=i-1; j >= 0; j--)
		{
			dp[j][i] = dp[j][i-1] + 1;
			for(int k=1; k <= i-j; k++)
			{
				int cnt = min(count[i][k], (i - j + 1) / k);
				int digit = digitLen(cnt);
				dp[j][i] = min(dp[j][i], dp[j][i - k * cnt] + 2 + digit + dp[i - k + 1][i]);
			}
		}
	}

	printf("%d", dp[0][N-1]);
	return 0;
}