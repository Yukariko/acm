#include <bits/stdc++.h>

using namespace std;

int main()
{
	int N, K;
	scanf("%d%d", &N, &K);

	long long left = 1, right = 1LL * N * N;
	while(left <= right)
	{
		long long mid = (left + right) / 2;
		long long cnt = 0;
		for(int i=1; i <= N; i++)
			cnt += min(mid - 1, 1LL * N * i) / i;

		if(cnt < K)
			left = mid + 1;
		else
			right = mid - 1;
	}

	printf("%lld", right);
	return 0;
}