#include <stdio.h>

int main()
{
	int N;
	int pack[501] = {};
	int a[500001];
	scanf("%d",&N);

	for(int i=1;i<=N;i++)
	{
		scanf("%d",&a[i]);
		pack[i / 1000] += a[i];
	}

	int M;
	scanf("%d",&M);

	for(;M--;)
	{
		int C, P, Q;
		scanf("%d%d",&C,&P);
		if(C == 1)
		{
			scanf("%d",&Q);
			a[P] += Q;
			pack[P / 1000] += Q;
		}
		else
		{
			int sum = 0, ret = 0;
			for(; sum + pack[ret] < P; ret++)
				sum += pack[ret];

			ret *= 1000;
			for(; sum + a[ret] < P; ret++)
				sum += a[ret];

			printf("%d\n",ret);
		}
	}

	return 0;
}
