#include <stdio.h>

const int d[2][8] = {
	{0,0,1,1,1,-1,-1,-1},
	{1,-1,0,1,-1,0,1,-1}
};

int main()
{
	int N;
	char map[1001][1001];
	scanf("%d ",&N);
	for(int i=0;i<N;i++)
		gets(map[i]);

	for(int i=0;i<N;i++)
	{
		for(int j=0;j<N;j++)
		{
			if(map[i][j] != '.')
				putchar('*');
			else
			{
				int nMine = 0;
				for(int k=0; k<8; k++)
				{
					int ny = i + d[0][k];
					int nx = j + d[1][k];
					if(ny >= N || ny < 0 || nx >= N || nx < 0 || map[ny][nx] == '.')
						continue;
					nMine += map[ny][nx] - '0';
				}
				putchar(nMine>=10?'M':nMine+'0');
			}
		}
		puts("");
	}

	return 0;
}