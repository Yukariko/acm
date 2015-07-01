#include <stdio.h>

int main()
{
	int N;
	int a[100001];
	int b[1000001]={};

	scanf("%d",&N);
	for(int i=0; i < N; i++)
	{
		scanf("%d",&a[i]);
		b[a[i]]++;
	}

	for(int i=0; i < N; i++)
	{
		int ret = 0;
		for(int j = 1; j*j <= a[i]; j++)
		{
			if(a[i] % j == 0)
			{
				ret += b[j];
				if(j != a[i] / j)
					ret += b[a[i]/j];
			}
		}
		printf("%d\n", ret-1);
	}

	return 0;
}