#include <bits/stdc++.h>

using namespace std;

const int S = 1132501;

int N, K;
int a[151];
int cost[153][153];

bitset<S> cache[151];

int main()
{
	scanf("%d", &N);
	for(int i=1; i <= N; i++)
		scanf("%d", &a[i]);
	scanf("%d", &K);

	if(K >= S)
	{
		printf("%d", K);
		return 0;
	}

	for(int i=1; i <= N; i++)
	{
		int sum = 0;
		int num = 0;
		for(int j=i; j <= N; j++)
		{
			sum += a[j];
			num += sum;
			cost[i][j] = num;
		}
	}

	cache[0].set(0, 1);

	for(int i=1; i <= N; i++)
	{
		cache[i].set(cost[1][i], 1);

		if(i <= N - 22)
		{
			for(int j=max(i - 22, 0); j < i; j++)
				cache[i] |= cache[j] << cost[j+2][i];
			continue;
		}

		for(int j=0; j < i; j++)
			cache[i] |= cache[j] << cost[j+2][i];
	}

	while(cache[N].test(K) == 1)
		K++;

	printf("%d", K);
	return 0;
}