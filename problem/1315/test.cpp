#include <bits/stdc++.h>

using namespace std;

int cache[1001][1001][2];
int dp[1001][1001];

int solve(int _str, int _int, int _point)
{
	int& ans = dp[_str][_int];
	if(ans != -1)
		return ans;

	ans = cache[_str][_int][0];
	_point = min(_point, 2000);
	for(int i=0; i <= _point; i++)
	{
		int _nstr = min(_str + i, 1000);
		int _nint = min(_int + _point - i, 1000);
		ans = max(ans, solve(_nstr, _nint, cache[_nstr][_nint][1] - cache[_str][_int][1]));
	}
	return ans;
}

int main()
{

	int N;
	scanf("%d",&N);
	
	vector<tuple<int,int,int>> a(N);
	for(int i; i <= N; i++)
		scanf("%d%d%d",&get<0>(a[i]), &get<1>(a[i]), &get<2>(a[i]));

	for(int i=1; i <= 1000; i++)
		for(int j=1; j <= 1000; j++)
			for(int k=0; k < N; k++)
				if(i >= get<0>(a[k]) || j >= get<1>(a[k]))
				{
					cache[i][j][0]++;
					cache[i][j][1] += get<2>(a[k]);
				}

	memset(dp, -1, sizeof(dp));
	printf("%d", solve(1, 1, cache[1][1][1]));
	return 0;
}