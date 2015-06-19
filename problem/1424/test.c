#include <stdio.h>

int main()
{
	int N,L,C;
	scanf("%d%d%d",&N,&L,&C);

	int max = 0;
	for(int i=L; i <= C; i+=L+1)
		max++;

	if(max % 13 == 0)
		max--;

	int ret = N / max;

	int mod = N % max;
	if(mod)
	{
		if(mod % 13 == 0 && mod == max - 1)
			ret+=2;
		else
			ret++;
	}

	printf("%d",ret);
	return 0;
}