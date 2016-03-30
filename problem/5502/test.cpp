#include <bits/stdc++.h>

using namespace std;

int N;
char a[5001];
int cache[5001][5001];

int solve(int left, int right)
{
	if(left >= right)
		return 0;

	int& ans = cache[left][right];
	if(ans != -1)
		return ans;

	if(a[left] == a[right])
		return ans = solve(left + 1, right - 1);
	return ans = 1 + min(solve(left + 1, right), solve(left, right - 1));
}

int main()
{
	memset(cache, -1, sizeof(cache));
	scanf("%d", &N);
	scanf("%s", a);
	printf("%d", solve(0, N-1));
	return 0;
}