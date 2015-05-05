#include <stdio.h>

int main()
{
	int N;
	scanf("%d",&N);
	int ret = 0;

	for(int i=1, j=1, k=0; i <= N; k+=4, j+=k,  i+=j)
		ret++;
	printf("%d",ret);
}