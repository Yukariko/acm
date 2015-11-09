#include <bits/stdc++.h>

using namespace std;

int main()
{
	int T;
	scanf("%d",&T);

	while(T--)
	{
		int N, M;
		scanf("%d%d",&N,&M);

		long long start = 0, end = 0;
		for(int i=0; i < M; i++)
		{
			int n;
			scanf("%d",&n);
			start *= 10;
			start += n;
		}

		for(int i=0; i < M; i++)
		{
			int n;
			scanf("%d",&n);
			end *= 10;
			end += n;
		}

		vector<int> a(N);
		for(int i=0; i < N; i++)
			scanf("%d",&a[i]);

		int ans = 0;
		for(int i=0; i < N; i++)
		{
			long long n = 0;
			for(int j=0; j < M; j++)
				n = n * 10 + a[(i+j)%N];
			if(n >= start && n <= end)
				ans++;
		}

		printf("%d\n", ans);
	}
	return 0;
}