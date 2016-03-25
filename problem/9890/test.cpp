#include <bits/stdc++.h>

using namespace std;

vector<pair<int, int>> a[2001];

int main()
{
	int N, C, M;
	scanf("%d%d%d", &N, &C, &M);

	for(int i=0; i < M; i++)
	{
		int u, v, w;
		scanf("%d%d%d", &u, &v, &w);
		a[u].push_back({v, w});
	}

	map<int, int> pack;
	int cap = 0;
	int ans = 0;
	for(int i=1; i <= N; i++)
	{
		ans += pack[i];
		cap -= pack[i];

		for(size_t j=0; j < a[i].size(); j++)
		{
			int there = a[i][j].first;
			int pick = min(C - cap, a[i][j].second);;
			cap += pick;
			pack[there] += pick;
			a[i][j].second -= pick;

			while(!pack.empty() && pack.rbegin()->first > there && a[i][j].second > 0)
			{
				int pick = min(a[i][j].second, pack.rbegin()->second);
				a[i][j].second -= pick;
				pack.rbegin()->second -= pick;
				pack[there] += pick;
				if(pack.rbegin()->second == 0)
					pack.erase(pack.rbegin()->first);
			}
		}
	}

	printf("%d", ans);
	return 0;
}