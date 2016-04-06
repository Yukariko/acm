#include <bits/stdc++.h>

using namespace std;

const char *dm = "URDL";
const int dy[] = {-1, 0, 1, 0};
const int dx[] = {0, 1, 0, -1};
const int INF = 987654321;

int N, M;
char a[501][501];
int cycle[501][501];

int main()
{
	scanf("%d%d", &N, &M);
	for(int i=0; i < N; i++)
		scanf("%s", a[i]);

	int sy, sx;
	scanf("%d%d", &sy, &sx);
	sy--, sx--;

	int ans = 0;
	char ansd = -1;
	for(int d=0; d < 4; d++)
	{
		memset(cycle, 0, sizeof(cycle));
		int y = sy, x = sx;
		int d_y = dy[d], d_x = dx[d];
		int cnt = 0;

		while(y >= 0 && y < N && x >= 0 && x < M)
		{
			cnt++;
			cycle[y][x]++;
			if(cycle[y][x] >= 4)
			{
				cnt = INF;
				break;
			}

			if(a[y][x] == '/')
			{
				int t = d_x;
				d_x = -d_y;
				d_y = -t;
			}
			else if(a[y][x] == '\\')
			{
				int t = d_x;
				d_x = d_y;
				d_y = t;
			}
			else if(a[y][x] == 'C')
			{
				cnt--;
				break;
			}

			y += d_y;
			x += d_x;
		}

		if(ans < cnt)
		{
			ansd = dm[d];
			ans = cnt;
		}
	}


	printf("%c\n", ansd);
	if(ans == INF)
		puts("Voyager");
	else
		printf("%d", ans);
	return 0;
}