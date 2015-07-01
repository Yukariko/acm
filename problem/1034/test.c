#include <stdio.h>
#include <string.h>

int max(int p, int q){return p>q?p:q;}

int main()
{
	int N,M;
	char a[51][51];

	scanf("%d%d ",&N,&M);
	for(int i=0; i < N; i++)
		gets(a[i]);

	int K;
	scanf("%d",&K);

	int ret = 0;

	for(int i=0; i < N; i++)
	{
		int zero = 0;
		for(int j=0; j < M; j++)
			if(a[i][j] == '0')
				zero++;

		if(zero > K || (K - zero) % 2)
			continue;

		int cur = 1;
		for(int j=i+1; j < N; j++)
			if(strcmp(a[i],a[j])==0)
				cur++;

		ret = max(ret, cur);
	}
	printf("%d",ret);
	return 0;
}