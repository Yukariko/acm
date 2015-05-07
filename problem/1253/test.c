#include <stdio.h>
#include <stdlib.h>

int N;
int a[2001];
char visit[2001];

void bin_search(int p, int q)
{
	int start = 0, end = N-1;
	int num = a[p] + a[q];
	
	while(start <= end)
	{
		int mid = (start + end)/2;
		if(a[mid] < num)
			start = mid + 1;
		else
			end = mid - 1;
	}
	for(int i=start;i<N && a[i] == num;i++)
		if(i != p && i != q)
			visit[i] = 1;
}

int cmp(int *p, int *q)
{
	return *p > *q? 1 : *p < *q? -1: 0;
}

int main()
{
	scanf("%d",&N);
	for(int i=0;i<N;i++)
		scanf("%d",&a[i]);
	
	qsort(a, N, 4, cmp);
	
	for(int i=0;i<N;i++)
		for(int j=i+1;j<N;j++)
			bin_search(i,j);
	
	int ret = 0;
	for(int i=0;i<N;i++)
		if(visit[i])
			ret++;
	printf("%d",ret);
	return 0;
}
