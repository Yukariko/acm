#include <bits/stdc++.h>

using namespace std;

const int INF = 987654321;

int path[101][101];

void getPath(vector<int>& paths, int u, int v)
{
	if(path[u][v])
	{
		getPath(paths, u, path[u][v]);
		getPath(paths, path[u][v], v);
		return;
	}
	paths.push_back(v);
}

int main()
{
	int N, M;
	scanf("%d%d", &N, &M);

	int d[101][101];
	for(int i=1; i <= N; i++)
		for(int j=1; j <= N; j++)
			d[i][j] = i == j? 0: INF;

	while(M--)
	{
		int u, v, w;
		scanf("%d%d%d", &u, &v, &w);
		d[u][v] = min(d[u][v], w);
	}

	for(int k=1; k <= N; k++)
		for(int i=1; i <= N; i++)
			if(d[i][k] != INF)
				for(int j=1; j <= N; j++)
					if(d[i][j] > d[i][k] + d[k][j])
						d[i][j] = d[i][k] + d[k][j], path[i][j] = k;

	for(int i=1; i <= N; i++)
	{
		for(int j=1; j <= N; j++)
			printf("%d ", d[i][j] == INF? 0: d[i][j]);
		puts("");
	}

	for(int i=1; i <= N; i++)
	{
		for(int j=1; j <= N; j++)
		{
			if(i == j || d[i][j] == INF)
			{
				puts("0");
				continue;
			}

			vector<int> paths;
			paths.push_back(i);
			
			getPath(paths, i, j);
			printf("%d ", paths.size());
			for(size_t k=0; k < paths.size(); k++)
				printf("%d ", paths[k]);
			puts("");
		}
	}

	return 0;
}