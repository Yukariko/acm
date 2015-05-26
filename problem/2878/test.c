#include <stdio.h>
#include <stdlib.h>

int cmp(int *p, int *q)
{
	return *p > *q? -1 : *p < *q? 1: 0;
}

int main()
{
	int M,N;
	int a[100001];  	

	scanf("%d%d",&M,&N);	
	for(int i=0;i < N; i++)
		scanf("%d",&a[i]);

	qsort(a,N,4,cmp);
	
	int start = 0, end = a[0];
	while(start <= end)
	{
		int mid = ((long long)start + end) / 2;
		long long s = 0;
		for(int i=0; i < N; i++)
		{
			if(a[i] > mid)
			{
				s += a[i] - mid;
			}
		}
		if(s >= M)
		{
			start = mid + 1;
		}
		else
		{
			end = mid - 1;
		}
	}
	
	for(int i=0; i < N; i++)
	{
		if(a[i] - start > 0)
		{
			M -= a[i] - start;
			a[i] = start;
		}
	}
	
	for(int i=0; M; i++)
	{
    	a[i]--;
		M--;
	}

	unsigned long long ret = 0;
	
	for(int i=0; i < N; i++)
		ret += (long long)a[i] * a[i];
	
	printf("%llu",ret);
	return 0;	
}
