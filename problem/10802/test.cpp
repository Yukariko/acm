#include <iostream>
#include <vector>
#include <algorithm>
#include <cstdio>
#include <cstring>

using namespace std;

const char *av = "0123456789";

const int MOD = 20150523;

int dp[100001][3][2][2];

int solve(const string &A, int pos, int mod, bool find, bool over)
{
	if(A[pos] == 0)
		return find || !mod;

	int &ans = dp[pos][mod][find][over];
	if(ans != -1)
		return ans;

	ans = 0;
	if(over == false)
		for(int i=0; av[i] && av[i] <= A[pos]; i++)
			ans = (ans + solve(A, pos+1, (mod + av[i]-'0') % 3,  find || (i && i % 3 == 0), av[i] < A[pos])) % MOD;

	else
		for(int i=0; av[i]; i++)
			ans = (ans + solve(A, pos+1, (mod + av[i]-'0') % 3, find || (i && i % 3 == 0), over)) % MOD;

	return ans;
}


int main()
{
	string A, B;
	cin >> A >> B;

	memset(dp, -1, sizeof(dp));
	int ansA = solve(A, 0, 0, false, false) - 1;

	memset(dp, -1, sizeof(dp));
	int ansB = solve(B, 0, 0, false, false) - 1;

	bool find = false;
	int mod=0;
	for(int i=0; A[i]; i++)
	{
		mod += A[i] - '0';
		if(A[i] > '0' && (A[i]-'0') % 3 == 0)
		{
			find = true;
			break;
		}
	}

	if(mod % 3 == 0)
		find = true;

	if(find == true)
		ansA--;

	int ans = ansB - ansA;
	if(ans < 0)
		ans += MOD;

	cout << ans;
	return 0;
}