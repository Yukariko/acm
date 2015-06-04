#include <stdio.h>
#include <stdlib.h>

int main()
{
	int X,K;
	scanf("%d%d",&X,&K);
	long long ret = 0;
	
	for(int i=0;K;K>>=1)
	{
		for(; X & (1LL << i); i++);
		if(K&1)
			ret |= 1LL << i;
		i++;
	}
	
	printf("%lld",ret);
	return 0;
}