#include <stdio.h>

#define range 200000

long long prime[17985];

int isPrime(long long n)
{
	for(int i=0;prime[i] * prime[i] <= n; i++)
		if(n % prime[i] == 0)
			return 0;
	return 1;
}

int main()
{
	char che[range+1] = {};
	for(long long i=2,k=0;i <= range; i++)
	{
		if(che[i] == 0)
		{
			prime[k++] = i;
			for(long long j = i * i; j <= range; j+=i)
				che[j] = 1;
		}
	}

	int T;
	scanf("%d",&T);
	for(;T--;)
	{
		long long N;
		scanf("%lld",&N);
		if(N <= 2)
		{
			puts("2");
			continue;
		}
		for(long long i=N&1?N:N+1; ; i += 2)
		{
			if(isPrime(i))
			{
				printf("%lld\n",i);
				break;
			}
		}
	}
}