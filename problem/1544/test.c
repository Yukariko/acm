#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int equal(char *p, char *q, int len)
{
	
	for(int i=0;i<len;i++)
	{
		int count = 0;
		for(int j=0;j<len;j++)
		{
			if(p[j] == q[(i+j)%len])
				count++;
		}
		if(count == len)
			return 1;
	}
	return 0;
}

int main()
{
	int N;
	char a[51][51];
	int len[51];
	
	scanf("%d ",&N);
	for(int i=0;i<N;i++)
		len[i] = strlen(gets(a[i]));

	char check[51] = {};
	int ret = 0;
	
	for(int i=0;i<N;i++)
	{
		if(check[i]) continue;
		ret++;
		check[i] = 1;
		for(int j=i+1;j<N;j++)
		{
			if(check[j]) continue;
			if(len[i] == len[j] && equal(a[i],a[j],len[i]))
				check[j] = 1;
		}
	}
	printf("%d",ret);
	return 0;
}
