#include <bits/stdc++.h>

using namespace std;

int main()
{
	int N, M;
	scanf("%d%d", &N, &M);
	
	int len = 0;
	for(int n=N; n; n/=10)
		len++;

	char a[5];
	sprintf(a, "%d", N);

	int n = min(N * len, M);
	for(int i=0; i < n; i++)
		putchar(a[i%len]);

	return 0;
}