#include <bits/stdc++.h>

using namespace std;

int main()
{
	int N, M;
	while(scanf("%d%d",&N,&M), N)
	{
		vector<pair<int,int>> a(N);
		for(int i=0; i < N; i++)
		{
			scanf("%*d%*d%d%d", &a[i].first, &a[i].second);
			a[i].second += a[i].first;
		}


		while(M--)
		{
			int start, duration;
			scanf("%d%d", &start, &duration);

			int ans = 0;
			for(int i=0; i < N; i++)
			{
				if(a[i].second <= start || a[i].first >= start + duration)
					continue;
				ans++;
			}

			printf("%d\n",ans);
		}

	}
	return 0;
}