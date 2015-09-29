#include <bits/stdc++.h>

using namespace std;

int N, M;
char a[11][11];

int pre_path[11];
int cache[11][1<<10];

int isOK(int left, int here)
{
	int ret = 0;
	for(int i=0; i < N; i++)
	{
		if((here & 1) == 0)
		{
			if(i != 0 && (left & (1 << (i-1))) == 0)
				return -1;

			if(i != N-1 && (left & (1 << (i+1))) == 0)
				return -1;

			if((left & (1 << i)) == 0)
				return -1;
			ret++;
		}
		here /= 2;
	}
	return ret;
}

int solve(int pos, int left)
{
	if(pos == M)
		return 0;

	int& ret = cache[pos][left];
	if(ret != -1)
		return ret;

	ret = 0;
	for(int i=0; i < (1 << N); i++)
	{
		if((i & pre_path[pos]) != pre_path[pos])
			continue;

		int get = isOK(left, i);
		if(get != -1)
			ret = max(ret, get + solve(pos+1, i));
	}
	return ret;
}

int main()
{
	int T;
	scanf("%d",&T);

	while(T--)
	{
		scanf("%d%d",&N,&M);
		for(int i=0; i < N; i++)
			scanf("%s",a[i]);

		memset(pre_path, 0, sizeof(pre_path));
		memset(cache, -1, sizeof(cache));

		for(int i=0; i < M; i++)
		{
			for(int j=0; j < N; j++)
			{
				pre_path[i] *= 2;
				pre_path[i] += a[j][i] == 'x';
			}
		}

		printf("%d\n",solve(0,(1 << N) - 1));
	}
	return 0;
}