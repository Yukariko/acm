#include <bits/stdc++.h>

using namespace std;

const int dy[] = {1, -1, 0, 0};
const int dx[] = {0, 0, 1, -1};

char a[103][103];
char key[27];
bool visit[103][103];
bool hasKey[27];

int main()
{
	int T;
	scanf("%d", &T);

	while(T--)
	{
		int N, M;
		scanf("%d%d", &N, &M);

		memset(a, '.', sizeof(a));
		for(int i=1; i <= N; i++)
			for(int j=1; j <= M; j++)
				scanf(" %c", &a[i][j]);
		N += 2;
		M += 2;

		scanf("%s", key);
		memset(hasKey, false, sizeof(hasKey));
		for(int i=0; key[i]; i++)
			hasKey[key[i] - 'a'] = true;


		memset(visit, false, sizeof(visit));
		queue<pair<int, int>> q;

		visit[0][0] = true;
		q.push({0, 0});

		int ans = 0;
		while(!q.empty())
		{
			int y = q.front().first;
			int x = q.front().second;
			q.pop();

			if(a[y][x] == '$' || (islower(a[y][x]) && !hasKey[a[y][x] - 'a']))
			{
				memset(visit, false, sizeof(visit));
				q = queue<pair<int, int>>();
				
				if(a[y][x] == '$')
				{
					ans++;
					a[y][x] = '.';
				}
				else
					hasKey[a[y][x] - 'a'] = true;

				visit[y][x] = true;
				q.push({y, x});
				continue;
			}

			for(int d=0; d < 4; d++)
			{
				int ny = y + dy[d];
				int nx = x + dx[d];
				if(ny < 0 || ny >= N || nx < 0 || nx >= M || visit[ny][nx] || a[ny][nx] == '*')
					continue;

				if(isupper(a[ny][nx]) && !hasKey[a[ny][nx] - 'A'])
					continue;

				visit[ny][nx] = true;
				q.push({ny, nx});
			}
		}

		printf("%d\n", ans);
	}
	return 0;
}