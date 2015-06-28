#include <stdio.h>

int a[6][3];
char visit[6][6];

int set(int p, int q, int m, int val)
{
	a[p][m] -= val;
	a[q][2-m] -= val;
	visit[p][q] += val;
}

int solve(int pos)
{
	if(pos == 5)
		return 1;

	if(a[pos][0] + a[pos][1] + a[pos][2] == 0)
		return solve(pos+1);

	int ret = 0;

	for(int i=pos+1; i < 6; i++)
	{
		for(int m=0; m < 3; m++)
		{
			if(visit[pos][i])
				continue;
			if(a[pos][m] && a[i][2-m])
			{
				set(pos,i,m,1);
				ret |= solve(pos);
				set(pos,i,m,-1);
				break;
			}
		}
	}
	return ret;
}

int main()
{
	for(int t=0; t < 4; t++)
	{
		for(int i=0; i < 6; i++)
			for(int j=0; j < 3; j++)
				scanf("%d",&a[i][j]);

		int err = 0;
		for(int i=0; i < 6; i++)
			if(a[i][0] + a[i][1] + a[i][2] != 5)
				err = 1;

		printf("%d ",err? 0: solve(0));
	}
	return 0;
}