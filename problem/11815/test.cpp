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

		bool find = false;

		long long left = 1, right = 1000000000;
		while(left <= right)
		{
			long long mid = (left + right) / 2;
			if(mid * mid == N)
			{
				find = true;
				break;
			}
			if(mid * mid < N)
				left = mid + 1;
			else
				right = mid - 1;
		}
		printf("%d ", find);
	}
	return 0;
}