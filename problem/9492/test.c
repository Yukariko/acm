#include <stdio.h>

int main()
{
	int N;
	for(;scanf("%d",&N),N;)
	{
		char a[1001][81];
		for(int i=0;i<N;i++)
			scanf("%s",a[i]);

		for(int i=0;i<N/2+N%2;i++)
		{
			puts(a[i]);
			if(i+N/2+N%2 < N)
				puts(a[i+N/2+N%2]);
		}
	}
	return 0;
}