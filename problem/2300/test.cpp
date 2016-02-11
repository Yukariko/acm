#include <bits/stdc++.h>

using namespace std;

const int INF = 987654321;

int N;
pair<int, int> a[10001];

int cache[10001];

int solve(int pos)
{
	if(pos == N)
		return 0;

	int& ans = cache[pos];
	if(ans != -1)
		return ans;

	ans = INF;
	int len = 0;

	for(int i=pos; i < N; i++)
	{
		len = max(len, max(a[i].first - a[pos].first, abs(a[i].second) * 2));
		ans = min(ans, len + solve(i+1));
	}

	return ans;
}

int main()
{
	memset(cache, -1, sizeof(cache));
	scanf("%d", &N);
	for(int i=0; i < N; i++)
		scanf("%d%d", &a[i].first, &a[i].second);

	sort(a, a + N);

	printf("%d", solve(0));
	return 0;
}