#include <stdio.h>

int N;
long long K;
long long dp[51][51];
char res[51];

long long solve(int pos,int left)
{
	if(pos == N)
	{
		if(left == 0)
			return 0;
		if(K-- == 0)
		{
			puts(res);
			exit(1);
		}
		return 1;
	}

	long long ret = 0;

	if(left >= 0)
	{
		long long *ret2 = &dp[pos][left];
		if(*ret2 != -1 && *ret2 < K)
		{
			K -= *ret2;
			return *ret2;
		}
		*ret2 = 0;
		res[pos] = '(';
		*ret2 += solve(pos+1,left+1);
		res[pos] = ')';
		*ret2 += solve(pos+1,left-1);
		ret = *ret2;
	}
	else
	{
		if((1LL << (N-pos)) < K)
		{
			K -= (1LL << (N-pos));
			return (1LL << (N-pos));
		}
		res[pos] = '(';
		ret += solve(pos+1,left);
		res[pos] = ')';
		ret += solve(pos+1,left);	
	}
	return ret;
}


int main()
{
	memset(dp,-1,sizeof(dp));
	scanf("%d%lld",&N,&K);
	solve(0,0);
	puts("-1");
	return 0;
}