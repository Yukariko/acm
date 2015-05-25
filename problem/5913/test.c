#include <stdio.h>

const int D[2][4] = {
	{1,-1,0,0},
	{0,0,1,-1}
};

char map[6][6];
int K;

int solve(int y1, int x1, int y2, int x2)
{
	if(y1 > 5 || y1 < 1 || y2 > 5 || y2 < 1)
		return 0;
	if(x1 > 5 || x1 < 1 || x2 > 5 || x2 < 1)
		return 0;
	if(map[y1][x1] || map[y2][x2])
		return 0;
	
	if(y1 == y2 && x1 == x2)
	{
		int count = 0;
		for(int i=1;i<=5;i++)
		{
			for(int j=1;j<=5;j++)
			{
				if(map[i][j] == 0)
				{
					count++;
					if(count == 2)
						return 0;		
				}
			}
		}
		return 1;
	}
	
	int ret = 0;
	
	map[y1][x1] = map[y2][x2] = 1;
	
	for(int i=0;i<4;i++)
	{
		for(int j=0;j<4;j++)
		{
			ret += solve(y1 + D[0][i], x1 + D[1][i], y2 + D[0][j], x2 + D[1][j]);
		}
	}
	
	map[y1][x1] = map[y2][x2] = 0;
		
	return ret;
}


int main()
{
	scanf("%d",&K);
	for(int i=0;i<K;i++)
	{
		int p,q;
		scanf("%d%d",&p,&q);
		map[p][q] = 1;
	}
	
	printf("%d",solve(1,1,5,5));
	
	return 0;
}
