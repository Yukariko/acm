#include <bits/stdc++.h>

using namespace std;

bool isPrime(long long N)
{
	for(long long i=2; i * i <= N; i++)
		if(N % i == 0)
			return false;
	return true;
}

long long N;
vector<long long> primes;

long long ans;
long long solve(int pos, int cnt, long long sum)
{
	if(pos == primes.size())
	{
		if(cnt % 2 == 0)
			return N / sum;
		else
			return -(N / sum);
	}

	long long ans = 0;
	ans += solve(pos + 1, cnt + 1, sum * primes[pos]);
	ans += solve(pos + 1, cnt, sum);
	return ans;
}


int main()
{
	scanf("%lld", &N);

	long long T = N;
	for(long long i=2; i * i <= T; i++)
	{
		if(T % i == 0)
			primes.push_back(i);
		while(T % i == 0)
			T /= i;
	}
	if(T > 1)
		primes.push_back(T);

	printf("%lld", solve(0, 0, 1));
	return 0;
}