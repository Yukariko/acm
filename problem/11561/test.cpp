#include <bits/stdc++.h>

using namespace std;

int main()
{
	int T;
	scanf("%d", &T);

	while(T--)
	{
		long long N;
		scanf("%lld", &N);

		long long ans = (sqrt(1 + 8 * N) - 1) / 2;
		printf("%lld\n", ans);
	}
	return 0;
}