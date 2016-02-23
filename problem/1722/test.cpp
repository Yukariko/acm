#include <bits/stdc++.h>

using namespace std;

int main()
{
	long long factorial[21];
	factorial[0] = factorial[1] = 1;
	for(int i=2; i < 21; i++)
		factorial[i] = factorial[i-1] * i;

	int N;
	scanf("%d", &N);

	int K;
	scanf("%d", &K);

	if(K == 1)
	{
		long long M;
		scanf("%lld", &M);

		vector<int> a(N);
		vector<bool> check(N+1, false);

		for(int i=0; i < N; i++)
		{
			for(int j=1; j <= N; j++)
			{
				if(check[j] == true)
					continue;

				if(M <= factorial[N-i-1])
				{
					check[j] = true;
					printf("%d ", j);
					break;
				}
				M -= factorial[N-i-1];
			}
		}
	}
	else
	{
		vector<int> a(N);
		for(int i=0; i < N; i++)
			scanf("%d", &a[i]);

		long long ans = 1;

		vector<bool> check(N+1, false);

		for(int i=0; i < N; i++)
		{
			for(int j=1; j <= N; j++)
			{
				if(check[j] == true)
					continue;
				if(a[i] == j)
					break;

				ans += factorial[N - i - 1];
			}

			check[a[i]] =  true;
		}

		printf("%lld", ans);
	}
	return 0;
}