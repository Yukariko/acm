#include <bits/stdc++.h>

using namespace std;

vector<int> adj[100001];
int a[1001][1001];

bool visit[100001];
bool visitCube[1001];

int main()
{
	int N, K, M;
	scanf("%d%d%d", &N, &K, &M);

	for(int i=0; i < M; i++)
	{
		for(int j=0; j < K; j++)
		{
			scanf("%d", &a[i][j]);
			adj[a[i][j]].push_back(i);
		}
	}

	queue<int> bfs;
	visit[1] = true;
	bfs.push(1);

	int ans = 1;
	while(!bfs.empty())
	{
		int size = bfs.size();
		while(size--)
		{
			int here = bfs.front();
			bfs.pop();

			if(here == N)
			{
				printf("%d", ans);
				return 0;
			}

			for(size_t p=0; p < adj[here].size(); p++)
			{
				int cube = adj[here][p];
				if(visitCube[cube])
					continue;
				visitCube[cube] = true;
				for(int i=0; i < K; i++)
				{
					if(!visit[a[cube][i]])
					{
						visit[a[cube][i]] = true;
						bfs.push(a[cube][i]);
					}
				}
			}
		}
		ans++;
	}

	puts("-1");
	return 0;
}