#include <bits/stdc++.h>

using namespace std;

const int INF = 987654321;

int N, T;
int a[101];
int b[101];

int cache[2][11001];

int main()
{
	scanf("%d%d", &N, &T);
	for(int i=0; i < N; i++)
		scanf("%d", &a[i]);
	for(int i=0; i < N; i++)
		scanf("%d", &b[i]);

	fill(&cache[0][0], &cache[2][0], INF);
	cache[0][0] = 0;
	for(int i=0; i < N; i++)
		for(int j=a[i]; j <= T + 120; j++)
			cache[0][j] = min(cache[0][j], 1 + cache[0][j - a[i]]);

	cache[1][0] = 0;
	for(int i=0; i < N; i++)
		for(int j=a[i]; j <= 120; j++)
			cache[1][j] = min(cache[1][j], 1 + cache[1][j - a[i]]);

	int ans = INF;
	for(int i=0; i < 120; i++)
		if(cache[0][T+i] && (i == 0 || cache[1][i]))
			ans = min(ans, cache[0][T+i] + cache[1][i]);

	printf("%d", ans == INF? -1: ans);
	return 0;
}