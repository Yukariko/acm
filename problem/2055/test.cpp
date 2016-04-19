#include <bits/stdc++.h>

using namespace std;

long long gcd(long long p, long long q)
{
	return q? gcd(q, p % q): p;
}

int main()
{
	int P, Q;
	scanf("%d%d", &P, &Q);

	long long ans = 0;
	for(int i=1; i <= P; i++)
		for(int j=1; j <= Q; j++)
		{
			long long cnt = 4;
			cnt += max(0LL, 2 * ((i + 1) * (j + 1) - 3 - gcd(i, j)));
			if(i > 1 && j > 1)
				cnt += 4 * (i - 1) * (j - 1);
			if(i > 1)
				cnt += 2 * (i - 1);
			if(j > 1)
				cnt += 2 * (j - 1);
			
			ans += cnt * (P - i + 1) * (Q - j + 1);
		}

	printf("%lld", ans);
	return 0;
}