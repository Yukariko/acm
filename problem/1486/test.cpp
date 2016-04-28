#include <bits/stdc++.h>

using namespace std;

const int dy[] = {1, -1, 0, 0};
const int dx[] = {0, 0, 1, -1};
const int INF = 987654321;

int N, M, T, D;
int a[26][26];
int d[26][26][26][26];

int main()
{
	scanf("%d%d%d%d", &N, &M, &T, &D);
	for(int i=0; i < N; i++)
	{
		for(int j=0; j < M; j++)
		{
			char c;
			scanf(" %c", &c);
			a[i][j] = c >= 'a'? 26 + c -'a': c - 'A';
		}
	}

	fill(&d[0][0][0][0], &d[26][0][0][0], INF);

	for(int i=0; i < N; i++)
	{
		for(int j=0; j < M; j++)
		{
			d[i][j][i][j] = 0;
			for(int dist=0; dist < 4; dist++)
			{
				int y = i + dy[dist];
				int x = j + dx[dist];
				if(y < 0 || y >= N || x < 0 || x >= M || abs(a[y][x] - a[i][j]) > T)
					continue;
				else if(a[y][x] <= a[i][j])
					d[i][j][y][x] = 1;
				else
					d[i][j][y][x] = (a[y][x] - a[i][j]) * (a[y][x] - a[i][j]);
			}
		}
	}

	for(int ki=0; ki < N; ki++)
		for(int kj=0; kj < M; kj++)
			for(int ui=0; ui < N; ui++)
				for(int uj=0; uj < M; uj++)
					if(d[ui][uj][ki][kj] != INF)
						for(int vi=0; vi < N; vi++)
							for(int vj=0; vj < M; vj++)
								d[ui][uj][vi][vj] = min(d[ui][uj][vi][vj], d[ui][uj][ki][kj] + d[ki][kj][vi][vj]);

	int ans = 0;
	for(int i=0; i < N; i++)
		for(int j=0; j < M; j++)
			if(d[0][0][i][j] + d[i][j][0][0] <= D)
				ans = max(ans, a[i][j]);

	printf("%d", ans);
	return 0;
}