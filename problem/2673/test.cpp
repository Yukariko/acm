#include <bits/stdc++.h>

using namespace std;

int N;
pair<int, int> a[51];
int cache[103][103];

int solve(int start, int end)
{
	int& ans = cache[start][end];
	if(ans != -1)
		return ans;

	ans = 0;
	for(int i=0; i < N; i++)
		if(start < a[i].first && a[i].second < end)
			ans = max(ans, 1 + solve(start, a[i].first) + solve(a[i].first, a[i].second) + solve(a[i].second, end));

	return ans;
}

int main()
{
	memset(cache, -1, sizeof(cache));
	scanf("%d", &N);

	for(int i=0; i < N; i++)
	{
		scanf("%d%d", &a[i].first, &a[i].second);
		if(a[i].first > a[i].second)
			swap(a[i].first, a[i].second);
	}

	printf("%d", solve(0, 101));
	return 0;
}