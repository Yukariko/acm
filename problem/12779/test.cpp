#include <bits/stdc++.h>

using namespace std;

long long gcd(long long p, long long q)
{
	return q? gcd(q, p % q): p;
}

int main()
{
	long long A, B;
	scanf("%lld%lld", &A, &B);

	long long p = B - A;
	long long q = floor(sqrt(B)) - floor(sqrtl(A)) + 1e-6;

	if(q == 0)
		puts("0");
	else
	{
		long long g = gcd(p, q);
		printf("%lld/%lld", q / g, p / g);
	}

	return 0;
}