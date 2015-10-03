#include <bits/stdc++.h>

using namespace std;

vector<int> X[100001];

int main()
{
	int T;
	scanf("%d",&T);

	while(T--)
	{
		int N;
		scanf("%d",&N);

		for(int i=0; i <= 100000; i++)
			X[i].clear();

		for(int i=0; i < N; i++)
		{
			int x, y;
			scanf("%d%d",&x,&y);
			X[x].push_back(y);
		}

		vector< pair<int, int> > ans;

		int curY = 0;
		for(int i=0; i <= 100000; i++)
		{
			if(X[i].empty())
				continue;

			sort(X[i].begin(), X[i].end());
			if(X[i][0] < curY)
			{
				for(int j=X[i].size()-1; j >= 0; j--)
					ans.push_back(make_pair(i, X[i][j]));
				curY = X[i][0];
			}
			else
			{
				for(int j=0; j < X[i].size(); j++)
					ans.push_back(make_pair(i, X[i][j]));
				curY = X[i].back();
			}
		}

		int M;
		scanf("%d",&M);

		while(M--)
		{
			int n;
			scanf("%d",&n);
			n--;
			printf("%d %d\n", ans[n].first, ans[n].second);
		}
	}
	return 0;
}