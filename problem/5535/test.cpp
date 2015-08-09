#include <iostream>
#include <cstring>
#include <cstdlib>

using namespace std;

struct wear
{
	int a, b, c;
};

int N, M;
int a[201];
wear w[201];

bool possible[201][201];

int dp[201][101];

int solve(int pos, int last)
{
	if(pos == N)
		return 0;

	int &ans = dp[pos][last];
	if(ans != -1)
		return ans;
	
	ans = 0;
	for(int i=0; i < M; i++)
		if(possible[pos][i] == true)
			ans = max(ans, abs(last - w[i].c) + solve(pos+1, w[i].c));

	return ans;
}

int main()
{
	memset(dp, -1, sizeof(dp));

	cin >> N >> M;
	for(int i=0; i < N; i++)
		cin >> a[i];

	for(int i=0; i < M; i++)
	{
		cin >> w[i].a >> w[i].b >> w[i].c;
		for(int j=0; j < N; j++)
			if(w[i].a <= a[j] && a[j] <= w[i].b)
				possible[j][i] = true;
	}
	
	int ans = 0;
	for(int i=0; i < M; i++)
		if(possible[0][i] == true)
			ans = max(ans, solve(1, w[i].c));

	cout << ans;
	return 0;
}