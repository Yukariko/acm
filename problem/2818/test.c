#include<stdio.h>

int main()
{
	int a=5,b=6,c=4,d=1,e=3,f=2;
	int R,C;
	long long n=0;
	
	scanf("%d%d",&R,&C);
	
	for(int i=0;i<R;i++)
	{
		int t;
		n += d;
		n += 14*((C-1)/4);
		for(int k=0;k<(C-1)%4;k++)
		{
			if(i%2)
			{t=b;b=c;c=d;d=e;e=t;}
			else
			{t=e;e=d;d=c;c=b;b=t;}
			n += d;
		}
		t=d;d=a;a=b;b=f;f=t;
	}
	printf("%lld",n);
	return 0;
}

