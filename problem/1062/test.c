#include <stdio.h>

int N,K;
char a[51][16];
int check[26];

int getCount()
{
	int ret = 0;
	for(int i=0;i<N;i++)
	{
		int ck = 1;
		for(int j=4;a[i][j];j++)
		{
			if(!check[a[i][j]-'a'])
			{
				ck = 0;
				break;
			}
		}
		if(ck) ret++;
	}
	return ret;
}

int max(int p,int q){return p>q?p:q;}

int solve(int pos, int count)
{
	if(count == 0)
	{
		return getCount();
	}
	
	int ret = 0;
	
	for(int i=pos;i<26;i++)
	{
		if(!check[i])
		{
			check[i] = 1;
			ret = max(ret, solve(i+1, count-1));
			check[i] = 0;
		}
	}
	return ret;
}

int main(void) {
	scanf("%d%d ",&N,&K);
	if(K < 5)
		return puts("0"),0;
		
	for(int i=0;i<5;i++)
		check["antci"[i]-'a']++;
		
	K-=5;
	for(int i=0;i<N;i++)
		gets(a[i]);
	
	printf("%d",solve(0,K));
	return 0;
}
