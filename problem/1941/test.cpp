#include <bits/stdc++.h>

using namespace std;

const int dy[] = {1, -1, 0, 0};
const int dx[] = {0, 0, 1, -1};

bool findGroup[1<<25];
char a[6][6];

int idx(int y, int x)
{
	return 1 << (y * 5 + x);
}

int solve(int pos, int sCnt, int mask)
{
	if(pos == 6)
	{
		if(sCnt < 4)
			return 0;
		if(findGroup[mask] == true)
			return 0;
		findGroup[mask] = true;
		return 1;
	}

	int ans = 0;
	for(int i=0; i < 5; i++)
	{
		for(int j=0; j < 5; j++)
		{
			if(!(mask & idx(i, j)))
				continue;

			for(int d=0; d < 4; d++)
			{
				int ny = i + dy[d];
				int nx = j + dx[d];

				if(ny < 0 || ny >= 5 || nx < 0 || nx >= 5 || mask & idx(ny, nx))
					continue;

				ans += solve(pos + 1, sCnt + (a[ny][nx] == 'S'), mask | idx(ny, nx));
			}
		}
	}

	return ans;
}


int main()
{
	for(int i=0; i < 5; i++)
		scanf("%s", a[i]);

	int ans = 0;
	for(int i=0; i < 5; i++)
		for(int j=0; j < 5; j++)
			ans += solve(0, a[i][j] == 'S', idx(i, j));

	printf("%d", ans);
	return 0;
}