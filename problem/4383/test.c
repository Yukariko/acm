#include <stdio.h>
#include <stdlib.h>

int main()
{
	int N;
	while(~scanf("%d",&N))
	{
		int a[3001];
		char visit[3001] = {};

		for(int i=0; i < N; i++)
			scanf("%d",a+i);

		int check = 0;
		for(int i=1; i < N; i++)
		{
			int n = abs(a[i] - a[i-1]);
			if(n > 0 && n < N && !visit[n])
				visit[n]++;
			else
			{
				check = 1;
				break;
			}
		}

		puts(check == 0?"Jolly": "Not jolly");
	}

	return 0;
}