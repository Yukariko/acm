#include <stdio.h>

int main()
{
	int E,S,M;
	scanf("%d%d%d",&E,&S,&M);
	
	for(int i=0; ; i++)
	{
		int vE,vS,vM;
		vE = i % 15 + 1;
		vS = i % 28 + 1;
		vM = i % 19 + 1;
		if(vE == E && vS == S && vM == M)
		{
			printf("%d",i+1);
			break;
		}
	}
	return 0;	
}
