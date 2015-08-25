#include <iostream>
#include <algorithm>

using namespace std;

int dp[10001][101];

int solve(int N, int M)
{
	if(N < M)
		return solve(M,N);

	if(N > M * 4 + 1)
		return 1 + solve(N - M, M);

	if(N % M == 0)
		return N / M;

	int &ret = dp[N][M];
	if(ret)
		return ret;
	ret = 987654321;

	int half = M / 2;
	for(int i=1; i <= half; i++)
		ret = min(ret, solve(N, M-i) + solve(N, i));
	
	half = N / 2;
	for(int i=1; i <= half; i++)
		ret = min(ret, solve(N-i, M) + solve(i, M));
	return ret;
}

int main()
{
	int N, M;
	cin >> N >> M;
	cout << solve(N, M);
	return 0;
}	