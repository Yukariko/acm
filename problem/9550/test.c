#include <stdio.h>

int main()
{
	int T;
	scanf("%d",&T);
	for(;T--;)
	{
		int N,K;
		scanf("%d%d",&N,&K);

		int ret = 0;
		for(int i=0;i<N;i++)
		{
			int p;
			scanf("%d",&p);
			ret += p / K;
		}

		printf("%d\n",ret);
	}
	return 0;
}