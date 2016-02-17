#include <bits/stdc++.h>

using namespace std;

int N;
int a[1001];

int cache[1001][1001][2];

int solve(int pos, int last, bool isDown)
{
	if(pos == N)
		return 0;

	int& ans = cache[pos][last][isDown];
	if(ans != -1)
		return ans;

	ans = solve(pos + 1, last, isDown);
	if(isDown == false && a[pos] > last)
		ans = max(ans, 1 + max(solve(pos + 1, a[pos], false), solve(pos + 1, a[pos], true)));
	if(isDown == true && a[pos] < last)
		ans = max(ans, 1 + solve(pos + 1, a[pos], true));
	return ans;
}

int main()
{
	memset(cache, -1, sizeof(cache));
	scanf("%d", &N);
	for(int i=0; i < N; i++)
		scanf("%d", &a[i]);
	printf("%d", solve(0, 0, false));
	return 0;
}