#include <bits/stdc++.h>

using namespace std;

int W[101];
int C[101];
bool dp[2][100001];

int main()
{
	int N;
	while(~scanf("%d", &N))
	{
		int V = 0;
		for(int i=0; i < N; i++)
		{
			scanf("%d%d", &W[i], &C[i]);
			V += W[i] * C[i];
		}

		if(V & 1)
		{
			puts("0");
			continue;
		}

		memset(dp, 0, sizeof(dp));
		for(int i=0; i < N; i++)
			for(int j=0; j <= V; j++)
			{
				if(dp[i&1^1][j])
					dp[i&1][j] = 1;
				if(j == 0 || dp[i&1^1][j])
					for(int k=1, v=j+W[i]; k <= C[i] && v <= V; k++, v+=W[i])
						dp[i&1][v] = 1;
			}

		printf("%d\n", !!dp[(N-1)&1][V/2]);
	}
	return 0;
}