#include <bits/stdc++.h>

using namespace std;

int N;
int a[101];

bool cache[2][52][23000];

int main()
{
	scanf("%d", &N);
	for(int i=0; i < N; i++)
		scanf("%d", &a[i]);

	int sum = 0;
	for(int i=0; i < N; i++)
		sum += a[i];

	cache[0][0][0] = 1;
	cache[1][0][0] = 1;
	for(int i=0; i < N; i++)
	{
		int cur = i & 1;
		int before = i & 1 ^ 1;
		int e = min(N / 2, i+1);
		for(int j=1; j <= e; j++)
			for(int k=a[i]; k < 23000; k++)
				cache[cur][j][k] |= cache[before][j-1][k-a[i]];
	}

	int ans = 23000;
	int l = 0;
	int r = 23000;

	for(int i=0; i < 23000; i++)
	{
		if(cache[(N-1)&1][N/2][i] == true)
		{
			if(abs(sum - i - i) < ans)
			{
				ans = abs(sum - i - i);
				l = min(sum - i, i);
				r = max(sum - i, i);
			}
		}
	}
	printf("%d %d", l, r);
	return 0;
}