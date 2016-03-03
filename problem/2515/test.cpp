#include <bits/stdc++.h>

using namespace std;

int N, S;
pair<int, int> a[300001];

int cache[300001];

int solve(int pos)
{
	if(pos == N)
		return 0;

	int& ans = cache[pos];
	if(ans != -1)
		return ans;

	ans = solve(pos + 1);

	int next = lower_bound(a + pos, a + N, make_pair(a[pos].first + S, 0)) - a;
	ans = max(ans, a[pos].second + solve(next));
	return ans;
}

int main()
{
	memset(cache, -1, sizeof(cache));
	scanf("%d%d", &N, &S);
	for(int i=0; i < N; i++)
		scanf("%d%d", &a[i].first, &a[i].second);

	sort(a, a + N);
	printf("%d", solve(0));
	return 0;
}