#include <bits/stdc++.h>

using namespace std;

const int MOD = 1000000;

char a[5001];
int cache[5001];

int solve(int pos)
{
	if(a[pos] == '0')
		return 0;
	if(a[pos] == 0)
		return 1;

	int& ans = cache[pos];
	if(ans)
		return ans;

	if(a[pos+1] && (a[pos] == '1' || (a[pos] == '2' && a[pos+1] <= '6')))
		ans += solve(pos+2);
	ans += solve(pos+1);
	return ans %= MOD;
}

int main()
{
	gets(a);
	printf("%d", solve(0));
	return 0;
}