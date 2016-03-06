#include <bits/stdc++.h>

using namespace std;

const long long INF = 10000 * 500001LL;
const int WRONG = 0;
const int ACCEPT = 1;
const int BONUS = 2;

int N, M;
int prob[500001], bonus[500001];
long long sum[500001];
long long dp[500001][3];

long long solve(int pos, int pick)
{
	if(pos == N)
		return 0;

	long long& ans = dp[pos][pick];
	if(ans != -INF)
		return ans;

	if(pick == ACCEPT)
		ans = prob[pos] + max(solve(pos + 1, ACCEPT), solve(pos + 1, WRONG));
	else if(pick == WRONG)
	{
		ans = -prob[pos] + solve(pos + 1, ACCEPT);
		if(pos + M < N)
			ans = -prob[pos] + sum[pos+M] - sum[pos] + solve(pos + M, BONUS);
	}
	else
	{
		ans = bonus[pos] + max(solve(pos + 1, ACCEPT), solve(pos + 1, WRONG));
		if(pos + M < N)
			ans = max(ans, bonus[pos] + sum[pos+M] - sum[pos] + solve(pos + M, BONUS));
	}

	return ans;
}

int main()
{
	scanf("%d%d", &N, &M);
	fill(&dp[0][0], &dp[N][0], -INF);

	for(int i=0; i < N; i++)
		scanf("%d", &prob[i]);
	for(int i=0; i < N; i++)
		scanf("%d", &bonus[i]);

	sum[0] = prob[0];
	for(int i=1; i < N; i++)
		sum[i] = sum[i-1] + prob[i];

	if(M > N)
	{
		printf("%lld", sum[N-1]);
		return 0;
	}

	printf("%lld", max({solve(0, ACCEPT), solve(0, WRONG), sum[M-1] + solve(M-1, BONUS)}));
	return 0;
}