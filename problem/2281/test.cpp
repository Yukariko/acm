#include <bits/stdc++.h>

using namespace std;

int N, M;
int a[1001];

int cache[1001][1001];

int solve(int pos, int width)
{
	if(pos == N)
		return 0;

	int& ans = cache[pos][width];
	if(ans != -1)
		return ans;

	ans = 987654321;
	if(width == a[pos])
		ans = min(ans, solve(pos + 1, M));
	else if(width > a[pos])
	{
		ans = min(ans, solve(pos + 1, width - a[pos] - 1));
		ans = min(ans, (width - a[pos]) * (width - a[pos]) + solve(pos + 1, M));
	}
	return ans;
}

int main()
{
	memset(cache, -1, sizeof(cache));
	scanf("%d%d", &N, &M);
	for(int i=0; i < N; i++)
		scanf("%d", &a[i]);

	printf("%d", solve(0, M));
	return 0;
}