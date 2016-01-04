#include <bits/stdc++.h>

using namespace std;

const short INF = 10000;

char a[501];

int cache[501][501];

int solve(int left, int right)
{
	if(left >= right)
		return 0;

	int& ans = cache[left][right];
	if(ans != -1)
		return ans;

	ans = max(solve(left+1, right), solve(left, right-1));
	if(a[left] != 'a' && a[left] != 'g')
		return ans;

	char pair = a[left] == 'a'? 't': 'c';
	for(int i=right; i > left; i--)
		if(a[i] == pair)
			ans = max(ans, 2 + solve(left+1, i-1) + solve(i+1, right));
	return ans;
}

int main()
{
	memset(cache, -1, sizeof(cache));
	int len = strlen(gets(a));
	printf("%d", solve(0, len-1));
	return 0;
}