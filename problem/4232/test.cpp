#include <bits/stdc++.h>

using namespace std;

int main()
{
	int N;
	while(scanf("%d", &N), N)
	{
		map<vector<int>, int> ck;

		int popularity = 0;
		for(int i=0; i < N; i++)
		{
			vector<int> t(5);
			for(int j=0; j < 5; j++)
				scanf("%d", &t[j]);
			sort(t.begin(), t.end());
			popularity = max(popularity, ++ck[t]);
		}

		int ans = 0;
		for(auto& pick : ck)
			if(pick.second == popularity)
				ans+=pick.second;

		printf("%d\n", ans);
	}
	return 0;
}