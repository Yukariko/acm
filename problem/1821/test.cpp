#include <bits/stdc++.h>

using namespace std;

int main()
{
	int N, K;
	scanf("%d%d", &N, &K);

	int a[11][11];
	a[1][1] = 1;
	for(int i=2; i <= N; i++)
	{
		a[i][1] = a[i][i] = 1;
		for(int j=2; j < i; j++)
			a[i][j] = a[i-1][j-1] + a[i-1][j];
	}

	int b[11];
	for(int i=1; i <= N; i++)
		b[i] = i;

	do
	{
		int num = 0;
		for(int i=1; i <= N; i++)
			num += b[i] * a[N][i];

		if(num == K)
		{
			for(int i=1; i <= N; i++)
				printf("%d ", b[i]);
			break;
		}

	} while(next_permutation(b + 1, b + N + 1));
	return 0;
}