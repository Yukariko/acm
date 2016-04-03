#include <bits/stdc++.h>

using namespace std;

const int MAX_N = 4000001;
int factor[MAX_N];
bool numSet[MAX_N];

vector<int> primes;

int main()
{
	int N, K, M;
	scanf("%d%d%d", &N, &K, &M);

	for(int i=2; i < MAX_N; i++)
	{
		if(numSet[i] == false)
		{
			primes.push_back(i);
			for(int j=i * 2; j < MAX_N; j+=i)
				numSet[j] = true;
		}
	}

	for(int i=0; i < primes.size() && primes[i] <= N; i++)
		for(long long n = primes[i]; n <= N; n *= primes[i])
			factor[primes[i]] += N / n;

	for(int i=0; i < primes.size() && primes[i] <= K; i++)
		for(long long n = primes[i]; n <= K; n *= primes[i])
			factor[primes[i]] -= K / n;

	for(int i=0; i < primes.size() && primes[i] <= N-K; i++)
		for(long long n = primes[i]; n <= N-K; n *= primes[i])
			factor[primes[i]] -= (N-K) / n;

	long long ans = 1;
	for(int i=0; i < primes.size() && primes[i] <= N; i++)
		while(factor[primes[i]]--)
			ans = ans * primes[i] % M;

	printf("%lld", ans);
	return 0;
}