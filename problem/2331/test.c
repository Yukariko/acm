#include <stdio.h>

int main()
{
	int A,P;
	int a[240001]={};
	scanf("%d%d",&A,&P);

	a[A] = 1;
	for(int i=2;;i++)
	{
		int nA=0;
		for(int j=A; j; j/=10)
		{
			int plus = 1;
			for(int k=0; k < P; k++)
				plus *= (j % 10);
			nA += plus;
		}
		if(a[nA])
		{
			printf("%d",a[nA]-1);
			break;
		}
		a[nA] = i;
		A = nA;
	}
	return 0;
}