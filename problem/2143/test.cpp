#include <bits/stdc++.h>

using namespace std;

int main()
{
	long long T;
	int N, M;

	scanf("%lld%d",&T,&N);
	vector<long long> a(N);
	for(int i=0; i < N; i++)
		scanf("%lld",&a[i]);

	scanf("%d",&M);
	vector<long long> b(M);
	for(int i=0; i < M; i++)
		scanf("%lld",&b[i]);

	vector<long long> c;
	for(int i=0; i < N; i++)
	{
		long long sum = 0;
		for(int j=i; j < N; j++)
		{
			sum += a[j];
			c.push_back(sum);
		}
	}

	sort(c.begin(), c.end());

	long long ans = 0;
	for(int i=0; i < M; i++)
	{
		long long sum = 0;
		for(int j=i; j < M; j++)
		{
			sum += b[j];
			auto hi = upper_bound(c.begin(), c.end(), T - sum);
			auto lo = lower_bound(c.begin(), c.end(), T - sum);
			if(*lo == T - sum)
				ans +=  hi - lo;
		}
	}
	printf("%lld",ans);
	return 0;
}