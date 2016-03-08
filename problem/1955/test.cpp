#include <bits/stdc++.h>

using namespace std;

int d[10001];
int factorial[101];
int main()
{
	int M = 1;

	factorial[0] = 1;
	while(factorial[M-1] * M <= 10000)
	{
		factorial[M] = factorial[M-1] * M;
		M++;
	}

	int N;
	scanf("%d", &N);

	for(int i=1; i <= N; i++)
		d[i] = i;
	
	for(int i=4; i <= N; i++)
	{
		for(int j=2; j * j <= i; j++)
			if(i % j == 0)
				d[i] = min(d[i], d[i/j] + d[j]);
		for(int j=1; j < i; j++)
			d[i] = min(d[i], d[j] + d[i-j]);

		for(int j=1; j < M && factorial[j] <= i; j++)
			d[i] = min(d[i], d[j] + d[i - factorial[j]]);
	}

	printf("%d", d[N]);
	return 0;
}