#include <bits/stdc++.h>

using namespace std;

const int dy[] = {1, 1, 1, -1, -1, -1, 0, 0};
const int dx[] = {-1, 0, 1, -1, 0, 1, 1, -1};

int main()
{
	int N, M;
	scanf("%d%d", &N, &M);

	char a[51][51];
	for(int i=0; i < N; i++)
		scanf("%s", a[i]);

	int ans = 0;
	int maxCnt = 0;
	for(int i=0; i < N; i++)
	{
		for(int j=0; j < M; j++)
		{
			int cur = 0;
			for(int d=0; d < 8; d++)
			{
				int ny = i + dy[d];
				int nx = j + dx[d];
				if(ny < 0 || ny >= N || nx < 0 || nx >= M)
					continue;
				cur += a[ny][nx] == 'o';
			}
			if(a[i][j] == 'o')
				ans += cur;
			else
				maxCnt = max(maxCnt, cur);
		}
	}

	printf("%d", ans / 2 + maxCnt);
	return 0;
}