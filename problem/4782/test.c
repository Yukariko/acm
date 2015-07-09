#include <stdio.h>

long long gcd(long long p,long long q){return q?gcd(q,p%q):p;}

int main()
{
	long long B,N;
	for(;scanf("%lld%lld",&B,&N),B;)
	{
		long long giyak = gcd(B,N);
		long long giyakB = B / giyak;
		long long giyakN = N / giyak;
		for(long long i = N * 2; i > 1; i -= giyakN)
		{
			if(i != N && ((B * i) * (2 * N - i)) % (N * N) == 0)
			{
				long long a = (B * i) * (2 * N - i) / (N * N);
				printf("%lld/%lld ",a,i);
			}

		}
		puts("");
	}
	return 0;
}