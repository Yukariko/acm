#include <stdio.h>

int cmp(int *p,int *q){return *p>*q?1:*p<*q?-1:0;}

int main()
{
	int N,C;
	int a[200001];

	scanf("%d%d",&N,&C);
	for(int i=0;i<N;i++)
		scanf("%d",&a[i]);

	qsort(a,N,4,cmp);

	int start = 0, end = a[N-1];
	while(start<=end)
	{
		int mid = (start + end)/2;
		int count=1;
		int stok = a[0];
		for(int i=1;i<N;i++)
		{
			if(a[i] - stok >= mid)
			{
				stok = a[i];
				count++;
			}
		}
		if(count >= C)
			start = mid + 1;
		else
			end = mid - 1;
	}

	printf("%d",end);
	return 0;
}
