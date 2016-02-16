#include <bits/stdc++.h>

using namespace std;

int N, H, W;
char a[33][33];

bool visit[33][33];
bool marking[33][33];

const int NOSOLUTION = 1;
const int AMBIGUOUS = 2;

const int dy[] = {1, -1, 0, 0, 1, -1, 1, -1};
const int dx[] = {0, 0, 1, -1, 1, -1, -1, 1};

int check(char *find, int y, int x, int d)
{
	if(*find == 0)
	{
		visit[y][x] = true;
		marking[y][x] = true;
		return 1;
	}

	visit[y][x] = true;

	int ny = y + dy[d];
	int nx = x + dx[d];

	if(ny < 0 || ny >= H || nx < 0 || nx >= W || a[ny][nx] != *find)
	{
		visit[y][x] = false;
		return false;
	}

	if(check(find+1, ny, nx, d))
	{
		marking[y][x] = true;
		return true;
	}

	visit[y][x] = false;
	return false;
}

int main()
{
	int T;
	scanf("%d", &T);

	while(T--)
	{
		scanf("%d%d%d", &N, &H, &W);
		for(int i=0; i < H; i++)
			scanf("%s", a[i]);

		memset(marking, false, sizeof(marking));

		int state = 0;

		for(int i=0; i < N; i++)
		{
			char b[33];
			scanf("%s", b);

			memset(visit, false, sizeof(visit));

			int find = 0;
			for(int j=0; j < H; j++)
				for(int k=0; k < W; k++)
					if(a[j][k] == b[0])
						for(int d=0; d < 8 && !visit[j][k]; d++)
							find += check(&b[1], j, k, d);

			if(!find)
				state = NOSOLUTION;
			else if(state == 0 && find > 1)
				state = AMBIGUOUS;
		}

		if(state == NOSOLUTION)
		{
			puts("no solution");
			continue;
		}

		if(state == AMBIGUOUS)
		{
			puts("ambiguous");
			continue;
		}

		bool find = false;
		for(int i=0; i < H; i++)
			for(int j=0; j < W; j++)
				if(marking[i][j] == false)
					putchar(a[i][j]), find = true;

		if(find == false)
			puts("empty solution");
		else
			puts("");
	}
	return 0;
}