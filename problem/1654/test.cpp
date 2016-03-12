#include <stdio.h>

int main()
{
	int K, N;
	int a[10001];

	scanf("%d%d",&K,&N);

	int max = 0;

	for(int i=0;i<K;i++)
	{
		scanf("%d",&a[i]);
		max = max < a[i]? a[i]: max;
	}

	long long start = 0, end = max;
	while(start <= end)
	{
		long long mid = (start + end) / 2;
		int val = 0;
		for(int i=0;i<K && val < N;i++)
			val += a[i] / mid;
		if(val >= N)
			start = mid + 1;
		else
			end = mid - 1;
	}
	printf("%lld",end);
	return 0;
}