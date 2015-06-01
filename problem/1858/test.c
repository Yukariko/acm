#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int cmp(int *p,int *q)
{
	return p[0] > q[0]? 1: p[0] < q[0]? -1: 0;
}

int getGrad(int x1,int y1,int x2,int y2)
{
	return abs((y2-y1) * 10000 / (x2-x1));
}

int min(int p,int q){return p>q?q:p;}
int max(int p,int q){return p>q?p:q;}

int main()
{
	int N;
	int p[50001][3];
	
	scanf("%d",&N);
	for(int i=0;i<N;i++)
	{
		p[i][2] = i+1;
		scanf("%d%d",&p[i][0],&p[i][1]);
	}
	
	int gradMax = 0;
	int ret1=1, ret2=1;
	int pi;
	
	qsort(p,N,12,cmp);
	
	for(int i=1;i<N;i++)
	{
		const int grad = getGrad(p[i-1][0],p[i-1][1],p[i][0],p[i][1]);
		if(gradMax < grad)
		{
			gradMax = grad;
			ret1 = min(p[i-1][2],p[i][2]);
			ret2 = max(p[i-1][2],p[i][2]);
			pi = i-1;
		}
	}
	
	for(int i=1;i<N;i++)
	{
		if(pi == i)
			continue;
		const int grad = getGrad(p[pi][0],p[pi][1],p[i][0],p[i][1]);
		if(gradMax == grad)
		{
			if(ret1 > p[i][2])
			{
				ret2 = ret1;
				ret1 = p[i][2];
			}
			else if(ret1 < p[i][2])
			{
				ret2 = min(ret2, p[i][2]);
			}
		}
	}
	
	printf("%d %d",ret1,ret2);
	return 0;	
}
