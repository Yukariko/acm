#include <bits/stdc++.h>

using namespace std;

const int ds[] = {-1, 0, 1};

int main()
{
	int N, M;
	scanf("%d%d", &N, &M);

	vector<bool> notJump(N+1, false);
	for(int i=0; i < M; i++)
	{
		int n;
		scanf("%d", &n);
		notJump[n] = true;
	}

	queue<pair<int, int>> bfs;
	set<pair<int, int>> check;

	check.insert({1, 1});
	bfs.push({1, 1});

	int ans = 0;
	while(!bfs.empty())
	{
		int size = bfs.size();
		while(size--)
		{
			int pos = bfs.front().first;
			int speed = bfs.front().second;
			bfs.pop();

			if(pos == N)
			{
				printf("%d", ans);
				return 0;
			}

			for(int d=0; d < 3; d++)
			{
				int nspeed = speed + ds[d];
				int npos = pos + nspeed;
				if(pos == 1 && ds[d] != 0)
					continue;
				if(nspeed < 1 || npos > N || notJump[npos] || check.count({npos, nspeed}))
					continue;

				check.insert({npos, nspeed});
				bfs.push({npos, nspeed});
			}
		}
		ans++;
	}

	puts("-1");
	return 0;
}