#include <stdio.h>
 
int main()
{
	int N,K;
	scanf("%d%d",&N,&K);

	int ret = 0;
	while(1)
	{
		int can = 0;
		for(int i=N; i; i/=2)
				can += i & 1;

		if(can <= K)
				break;
		ret++;
		N++;
	}
	printf("%d", ret);
	return 0;
}
