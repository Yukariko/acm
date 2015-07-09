#include <stdio.h>

char res[101];
int a[101];
int N;
int solve(int pos)
{
	if(pos == N)
	{
		for(int i=0; i < N; i++)
			if(res[i] != a[i])
				return 0;
		return 1;
	}

	int ret = 0;
	for(int i=0; i < N; i++)
	{
		res[pos] = i;
		a[i]++;
		ret += solve(pos+1);
		a[i]--;
	}
	return ret;
}

int main()
{
	int T;
	scanf("%d",&T);

	for(;T--;)
	{
		scanf("%d",&N);
		printf("%d\n",N >= 7? 1: solve(0));
	}

	return 0;
}