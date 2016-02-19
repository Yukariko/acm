#include <bits/stdc++.h>

using namespace std;

const int dy[] = {1, -1, 0, 0};
const int dx[] = {0, 0, 1, -1};

const int D = 0;
const int U = 1;
const int R = 2;
const int L = 3;

const char *moved = "DURL";

int N, M;
int a[1001][1001];

int visit[1001][1001];


int main()
{
	scanf("%d%d", &N, &M);

	for(int i=0; i < N; i++)
		for(int j=0; j < M; j++)
			scanf("%d", &a[i][j]);

	if(M % 2)
	{
		for(int i=0; i < M; i++)
		{
			for(int j=1; j < N; j++)
				putchar(i % 2? 'U': 'D');
			if(i != M-1)
				putchar('R');
		}
	}
	else if(N % 2)
	{
		for(int i=0; i < N; i++)
		{
			for(int j=1; j < M; j++)
				putchar(i % 2? 'L': 'R');
			if(i != N-1)
				putchar('D');
		}
	}
	else
	{
		int my=1, mx=0;
		for(int i=0; i < N; i++)
		{
			for(int j=0; j < M; j++)
			{
				if((i+j) % 2 && a[my][mx] > a[i][j])
				{
					my = i;
					mx = j;
				}
			}
		}

		visit[my][mx] = 3;
		int y = 0, x = 0;

		int cnt = 0;

		bool special = false;
		int priority[] = {U, R, L, D};
		if(y == N-2 && x == 0)
		{
			priority[0] = D;
			priority[1] = U;
			priority[2] = R;
			priority[3] = L;
			special = true;
		}

		while(y != N-1 || x != M-1)
		{
			cnt++;
			visit[y][x] = cnt;
			

			for(int i=0; i < 4; i++)
			{
				int ny = y + dy[priority[i]];
				int nx = x + dx[priority[i]];

				if(ny < 0 || ny >= N || nx < 0 || nx >= M || visit[ny][nx])
					continue;

				y = ny;
				x = nx;
				putchar(moved[priority[i]]);

				if(priority[i] == D && special == false && ((x == 0 && priority[1] == L) || (x == M-1 && priority[1] == R) ))
				{
					swap(priority[1], priority[2]);
				}

				if(y == N-2 && x == 0)
				{
					priority[0] = D;
					priority[1] = U;
					priority[2] = R;
					priority[3] = L;
					special = true;
				}
				break;
			}
		}

		if(cnt != N * M - 2)
		{
			printf("%d", 1 % 0);
			return 0;
		}
	}
	return 0;
}