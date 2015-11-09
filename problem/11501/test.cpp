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

		vector<int> a(N);
		vector<pair<int,int>> b(N);

		for(int i=0; i < N; i++)
		{
			scanf("%d",&a[i]);
			b[i].first = -a[i];
			b[i].second = i;
		}

		sort(b.begin(), b.end());

		long long ans = 0;
		int top = 0;
		int stok = 0;
		for(int i=0; i < N; i++)
		{
			while(b[top].second < i)
				top++;

			if(-b[top].first == a[i])
			{
				ans += 1LL * stok * a[i];
				stok = 0;
			}
			else
			{
				ans -= a[i];
				stok++;
			}
		}
		printf("%lld\n", ans);
	}
	return 0;
}