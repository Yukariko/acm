#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int max(int p,int q){return p>q?p:q;}

int main()
{
	int N,M;
	int a[100001];
	int sum =0;

	scanf("%d%d",&N,&M);
	for(int i=0;i<N;i++)
	{
		scanf("%d",a+i);
		sum += a[i];
	}

	int start = 0, end = sum;

	while(start <= end)
	{
		int mid = (start+end)/2;
		int count=1;
		int curSum = 0;
		for(int i=0;i<N;i++)
		{
			if(curSum + a[i] <= mid)
				curSum += a[i];
			else
			{
				count++;
				curSum = a[i];
			}
		}
		if(count > M)
			start = mid + 1;
		else
			end = mid - 1;
	}

	printf("%d",start);
	return 0;
}
