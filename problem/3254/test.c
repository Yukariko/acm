#include <stdio.h>
#include <string.h>

char map[8][8] = {};

const int d[2][4] = {
	{0,1,-1,1},
	{1,0,1,1}
};

void put(int place, int turn)
{
	for(int i=2;i<=7;i++)
	{
		if(map[i][place])
		{
			map[i-1][place] = turn;
			break;
		}
	}
}

int win(int turn)
{
	for(int i=1; i <= 6; i++)
	{
		for(int j=1; j <= 7; j++)
		{
			if(map[i][j] == turn)
			{
				for(int k=0; k < 4; k++)
				{
					int check = 4;
					for(int cnt = 0; cnt < 4; cnt++)
					{
						int ny = i+d[0][k]*cnt;
						int nx = j+d[1][k]*cnt;
						if(ny < 1 || ny > 6 || nx < 1 || nx > 7)
							break;
						if(map[ny][nx] == turn)
							check--;
					}
					if(check == 0)
						return 1;					
				}
			}
		}
	}
	return 0;
}

int main()
{
	memset(map[7],-1,8);
	for(int i=1;i<=21;i++)
	{
		int s,j;
		scanf("%d%d",&s,&j);
		put(s,1);
		if(win(1))
			return printf("sk %d",i);
		put(j,2);
		if(win(2))
			return printf("ji %d",i);
	}
	puts("ss");
	return 0;
}