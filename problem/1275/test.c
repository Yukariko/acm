#include <stdio.h>
#include <stdlib.h>

int main()
{
	int N,Q;
	int a[100001] = {};
	long long pack[1001] = {};
	scanf("%d%d",&N,&Q);
	for(int i=1;i<=N;i++)
	{
		scanf("%d",&a[i]);
		pack[i / 1000] += a[i];
	}
	
	for(;Q--;)
	{
		int x,y,p,q;
		scanf("%d%d%d%d",&x,&y,&p,&q);
		if(x > y)
		{
			int t = x;
			x = y;
			y = t;
		}
		long long ret = 0;
		
		for(int i=x/1000, z=y/1000;i<=z;i++)
			ret += pack[i];
		
		for(int i=x/1000*1000; i < x; i++)
			ret -= a[i];
		
		for(int i=y/1000*1000 + 999; i > y; i--)
			ret -= a[i];
		
		printf("%lld\n",ret);
		
		pack[p / 1000] -= a[p];
		pack[p / 1000] += q;
		a[p] = q;
	}
	return 0;
}