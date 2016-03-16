#include <bits/stdc++.h>

using namespace std;

long long _pow(long long A, long long B, long long limit)
{
	long long ans = 1;
	while(B--)
	{
	 ans *= A;
	 if(ans > limit * A)
	 	return -987654321;
	}
	return ans;
}

int main()
{
	long long B, N;
	while(scanf("%lld%lld", &B, &N), B)
	{
		long long ans = 0;
		long long diff = 987654321;
		for(long long i=1; i <= B; i++)
		{
			long long num = _pow(i, N, B);
			if(llabs(B - num) < diff)
			{
				diff = llabs(B - num);
				ans = i;
			}
		}
		printf("%lld\n", ans);
	}
	return 0;
}