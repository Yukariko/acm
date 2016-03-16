#include <bits/stdc++.h>

using namespace std;

const int dy[] = {0, 1};
const int dx[] = {1, 0};

int N, M;
char a[21][21];

int main()
{
	scanf("%d%d", &N, &M);
	for(int i=0; i < N; i++)
		scanf("%s", a[i]);

	string ans = "|";

	for(int i=0; i < N; i++)
	{
		for(int j=0; j < M; j++)
		{
			if(a[i][j] == '#')
				continue;

			for(int d=0; d < 2; d++)
			{
				if(dy[d] && i > 0 && a[i - dy[d]][j] != '#')
					continue;
				if(dx[d] && j > 0 && a[i][j - dx[d]] != '#')
					continue;
				string s;
				int y = i;
				int x = j;
				while(1)
				{
					if(y >= N || x >= M || a[y][x] == '#')
						break;
					s += a[y][x];
					y += dy[d];
					x += dx[d];
				}
				if(s.length() > 1)
					ans = min(ans, s);
			}
		}
	}

	puts(ans.c_str());
	return 0;
}