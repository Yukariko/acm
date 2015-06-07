#include <stdio.h>

int N;
char price[16][16];
char dp[16][10][32780];

int max(int p,int q){return p>q?p:q;}

char solve(char pos, char maxPrice, unsigned short visit)
{
	char *ret = &dp[pos][maxPrice][visit];

	if(*ret != -1)
		return *ret;

	*ret = 0;

	for(int i=0;i<N;i++)
		if((visit & 1 << i) == 0 && maxPrice <= price[pos][i]-'0')
			*ret = max(*ret, 1 + solve(i, price[pos][i]-'0', visit | (1 << i)));
	return *ret;
}
int main()
{
	memset(dp,-1,sizeof(dp));
	scanf("%d ",&N);
	for(int i=0;i<N;i++)
		gets(price[i]);

	printf("%d",1+solve(0,0,1));
	return 0;
}
