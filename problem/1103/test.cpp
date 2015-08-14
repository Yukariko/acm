#include <iostream>
#include <algorithm>

using namespace std;

int N, M;
char a[51][51];

const int d[2][4] = {
	{1,-1,0,0},
	{0,0,1,-1}
};

int dp[51][51];

int solve(int y, int x)
{
	if(y < 0 || y >= N || x < 0 || x >= M || a[y][x] == 'H')
		return 0;

	int jump = a[y][x]-'0';

	int& ret = dp[y][x];
	if(ret)
	{
		if(ret == -1)
		{
			cout << -1;
			exit(1);
		}
		return ret;
	}

	ret = -1;

	int keep;
	for(int i=0; i < 4; i++)
		keep = max(keep, 1 + solve(y+d[0][i]*jump,x+d[1][i]*jump));

	return ret = keep;
}

int main()
{
	cin >> N >> M;
	for(int i=0; i < N; i++)
		cin >> a[i];

	int ans = solve(0,0);

	cout << ans;
	return 0;
}