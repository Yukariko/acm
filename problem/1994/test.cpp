#include <bits/stdc++.h>

using namespace std;

int N;
int a[2001];

int cache[2001][2001];

int main()
{
	scanf("%d", &N);
	for(int i=0; i < N; i++)
		scanf("%d", &a[i]);
	sort(a, a + N);

	int ans = 0;
	int cur = 1;
	for(int i=1; i < N; i++)
	{
		if(a[i-1] != a[i])
			cur = 0;
		cur++;
		ans = max(ans, cur);
	}
	for(int i=0; i < N; i++)
	{
		cache[i][i] = 1;
		for(int j=i+1; j < N; j++)
			cache[i][j] = 2;
	}

	for(int i=0; i < N; i++)
	{
		for(int j=i+1; j < N; j++)
		{
			int diff = a[j] - a[i];
			auto lo = lower_bound(a, a + i + 1, a[i] - diff);
			int idx = lo - a;
			if(*lo == a[i] - diff)
				cache[i][j] = max(cache[i][j], cache[idx][i] + 1);
		}
	}

	for(int i=0; i < N; i++)
		for(int j=i; j < N; j++)
			ans = max(ans, cache[i][j]);
	printf("%d", ans);
	return 0;
}