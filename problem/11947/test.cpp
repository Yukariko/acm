#include <bits/stdc++.h>

using namespace std;

long long rev(long long N)
{
	long long ans = 0;
	for(long long i=1; i <= N; i *= 10)
	{
		int n = (N / i) % 10;
		ans += i * (9 - n);
	}
	return ans;
}

int main()
{
	int T;
	scanf("%d", &T);

	while(T--)
	{
		long long N;
		scanf("%lld", &N);

		int len = 0;
		for(int n=N; n; n/=10)
			len++;

		long long bound = 0;
		for(int i=0; i < len; i++)
			bound = bound * 10 + (i==0? 4: 9);

		if(N > bound)
			N = bound;
		printf("%lld\n", 1LL * N * rev(N));
	}
	return 0;
}