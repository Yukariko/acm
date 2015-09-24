#include <iostream>
#include <algorithm>
#include <cstring>
#include <vector>
#include <cstdio>
#include <map>

using namespace std;


int main()
{
	int N, K;
	scanf("%d%d",&N,&K);

	static int a[2000001] = {};
	for(int i=0; i < N; i++)
	{
		int n;
		scanf("%d",&n);
		a[n+1000000]++;
	}

	for(int i=0; i <= 2000000; i++)
	{
		if(K <= a[i])
		{
			printf("%d",i - 1000000);
			return 0;
		}
		K -= a[i];
	}

	return 0;
}