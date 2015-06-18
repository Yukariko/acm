#include <stdio.h>

int main()
{
	int a[30001];
	int b[3001]={};
	int N,D,K,C;
	scanf("%d%d%d%d",&N,&D,&K,&C);
	
	for(int i=0;i<N;i++)
	  scanf("%d",&a[i]);
	  
	int ret = 0;
	for(int i=0;i<K;i++)
		ret += b[a[i]]++?0:1;
	
	int store = ret;
	ret += b[C]?0:1;
	
	for(int i=K;i<N+K;i++)
	{
		store -= --b[a[(i-K)%N]]?0:1;
		store += b[a[i%N]]++?0:1;
		int t=b[C]?0:1;
		ret = ret < store + t? store + t: ret;
	}
	printf("%d",ret);
	return 0;
}

