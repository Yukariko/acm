#include <iostream>
#include <algorithm>
#include <cstdio>
#include <vector>

using namespace std;

int main()
{
	int T;
	scanf("%d",&T);

	for(int tc=1; tc <= T; tc++)
	{
		int N;
		scanf("%d",&N);

		vector< pair<int, pair<int, int> > > a(N);

		for(int i=0; i < N; i++)
			scanf("%d%d%d",&a[i].first, &a[i].second.second, &a[i].second.first);

		sort(a.begin(),a.end());

		int ans = 1;
		int day = a[0].first;
		int end = a[0].second.first;

		for(int i=1; i < N; i++)
		{
			if(day == a[i].first)
			{
				if(a[i].second.second >= end)
				{
					ans++;
					end = a[i].second.first;
				}
			}
			else
			{
				ans++;
				day = a[i].first;
				end = a[i].second.first;
			}
		}

		printf("Scenario #%d:\n",tc);
		printf("%d\n\n",ans);
	}
	return 0;
}