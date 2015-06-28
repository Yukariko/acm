#include <stdio.h>

int main()
{
	int T;
	scanf("%d",&T);
	for(;T--;)
	{
		int N;
		int a[101]={};
		scanf("%d",&N);
		for(int i=1;i<=N;i++)
			for(int j=i; j <= N; j+=i)
				a[j] = !a[j];

		int ret = 0;
		for(int i=1; i<=N; i++)
			ret += a[i];
		printf("%d\n",ret);
	}
	return 0;
}