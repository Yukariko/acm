#include <bits/stdc++.h>

using namespace std;

int main()
{
	int T;
	scanf("%d", &T);

	while(T--)
	{
		int K, N, M;
		scanf("%d%d%d", &K, &N, &M);

		vector<vector<int>> a(N+1);
		vector<int> b(N+1, 0);

		while(M--)
		{
			int u, v;
			scanf("%d%d", &u, &v);
			a[u].push_back(v);
			b[v]++;
		}

		vector<pair<int, int>> strahler(N+1, make_pair(0, 0));

		queue<int> q;
		for(int i=1; i <= N; i++)
			if(b[i] == 0)
				q.push(i), strahler[i] = {1, 0};


		int ans = 0;
		while(!q.empty())
		{
			int here = q.front();
			q.pop();

			for(size_t i=0; i < a[here].size(); i++)
			{
				int there = a[here][i];
				b[there]--;
				if(strahler[here].first > strahler[there].first)
					strahler[there] = {strahler[here].first, 1};
				else if(strahler[here].first == strahler[there].first)
					strahler[there].second++;

				if(b[there] == 0)
				{
					if(strahler[there].second > 1)
						strahler[there].first++;
					q.push(there);
				}
			}
		}
		
		printf("%d %d\n", K, strahler[N].first);
	}
	return 0;
}