#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cstring>

using namespace std;

int N;
int a[21];
int d[1<<20];
int sum;

bool solve2(int all)
{
	for(int i=all; i; i=((i-1)&all))
	{
		int x = (~i&all);
		if(d[i] == d[x])
			return true;
	}
	return false;
}

bool solve(int all)
{
	for(int i=1; i*2 < all; i++)
	{
		int x = (~i&all);
		if(d[i] == d[x] && solve2(i) && solve2(x))
			return true;
	}
	return false;
}

int main()
{
	int T;
	scanf("%d",&T);

	while(T--)
	{
		sum = 0;
		scanf("%d",&N);
		for(int i=0; i < N; i++)
		{
			scanf("%d",&a[i]);
			sum += a[i];
		}

		if(sum % 4)
		{
			puts("no");
			continue;
		}

		d[0] = 0;
		for(int i=0; i < N; i++)
			for(int j=0; j < (1<<i); j++)
				d[(1<<i) + j] = d[j] + a[i];

		puts(solve((1<<N)-1)? "yes": "no");
	}
	return 0;
}