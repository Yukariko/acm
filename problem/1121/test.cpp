#include <bits/stdc++.h>

using namespace std;

int N, K;
int a[2001];
long long cache[11][50002];

int main()
{
	scanf("%d", &N);
	for(int i=0; i < N; i++)
		scanf("%d", &a[i]);
	scanf("%d", &K);

	sort(a, a + N);

	cache[0][0] = 1;
	for(int i=0; i < N; i++)
		for(int j=K; j >= 1; j--)
			for(int k=0; k <= 50001; k++)
				if(j < K || k > a[i])
					cache[j][min(k + a[i], 50001)] += cache[j-1][k];

	long long ans = 0;
	for(int i=0; i <= 50001; i++)
		ans += cache[K][i];

	printf("%lld", ans);
	return 0;
}