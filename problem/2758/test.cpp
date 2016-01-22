#include <bits/stdc++.h>

using namespace std;

int N, M;
long long cache[11][2001];

int main()
{
	int T;
	scanf("%d", &T);

	for(int i=0; i <= 1000; i++)
		cache[0][i] = 1;

	for(int i=1; i <= 10; i++)
		for(int j=1; j <= 2000; j++)
			cache[i][j] += cache[i][j-1] + cache[i-1][j / 2];

	while(T--)
	{
		scanf("%d%d", &N, &M);
		printf("%lld\n", cache[N][M]);
	}
	return 0;
}