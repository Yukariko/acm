#include <bits/stdc++.h>

using namespace std;

int main()
{
	int T;
	scanf("%d", &T);

	while(T--)
	{
		int N, K;
		scanf("%d%d", &N, &K);

		vector<pair<int, int>> a(N);
		for(int i=0; i < N; i++)
			scanf("%d%d", &a[i].first, &a[i].second);
		sort(a.begin(), a.end());

		double left = 0, right = 200000000;
		for(int d=0; d < 100; d++)
		{
			double mid = (left + right) / 2;
			double minY = a[0].second, maxY = a[0].second;
			int cnt = 0;
			for(int i=0; i < N; i++)
			{
				minY = min<double>(minY, a[i].second);
				maxY = max<double>(maxY, a[i].second);
				if(maxY - minY > mid)
				{
					cnt++;
					minY = maxY = a[i].second;
				}
			}
			cnt++;

			if(cnt > K)
				left = mid;
			else
				right = mid;
		}

		printf("%.1f\n", left / 2);
	}
	return 0;
}