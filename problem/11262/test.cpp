#include <bits/stdc++.h>

using namespace std;

int main()
{
	int T;
	scanf("%d",&T);

	while(T--)
	{
		int N;
		scanf("%d",&N);

		vector<long long> a(N);
		for(int i=0; i < N; i++)
			scanf("%lld",&a[i]);

		long long sum = 0;
		for(int i=0; i < N; i++)
			sum += a[i] * 10000;

		sum /= N;
		long long ans = 0;
		for(int i=0; i < N; i++)
			if(a[i] * 10000 > sum)
				ans += 10000;

		ans = ans * 100 / N;
		ans += 5;
		sum += 5;
		printf("%lld.%03lld %lld.%03lld%%\n", sum / 10000, sum % 10000 / 10, ans / 10000, ans % 10000 / 10);
	}
	return 0;
}