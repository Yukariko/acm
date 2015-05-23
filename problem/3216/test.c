#include <stdio.h>


int main()
{
	int N;
	int D[100001];
	int V[100001];

	scanf("%d",&N);
	for(int i=0;i<N;i++)
		scanf("%d%d",&D[i],&V[i]);
	
	int ret = 0;
	int time = 0;
	for(int i=0;i<N;i++)
	{
		time -= V[i];
		if(time < 0)
		{
			ret -= time;
			time = 0;
		}
		time += D[i];
	}

	printf("%d",ret);
	return 0;
}