#include <bits/stdc++.h>

using namespace std;

long long gcd(long long a, long long b)
{
	return b? gcd(b, a % b): a;
}

long long lcm(long long a, long long b)
{
	return a * b / gcd(a, b);
}

int main()
{
	long long A, B;
	scanf("%lld%lld", &A, &B);
	if(A > B)
		swap(A, B);

	long long N = B - A;
	long long ans = 1;
	long long aa = 1LL << 62;
	for(long long i=1; i * i <= N; i++)
	{
		if(N % i == 0)
		{
			long long diff = (A + i - 1) / i * i - A;
			if(diff == 0)
				diff += i;
			if(aa > lcm(A + diff, B + diff))
			{
				aa = lcm(A + diff, B + diff);
				ans = diff;
			}

			if(N / i != i)
			{
				long long diff = (A + N / i - 1) / (N / i) * (N / i) - A;
				if(diff == 0)
					diff += N / i;
				if(aa > lcm(A + diff, B + diff))
				{
					aa = lcm(A + diff, B + diff);
					ans = diff;
				}
			}
		}
	}

	printf("%lld", ans);
	return 0;
}