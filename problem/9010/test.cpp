#include <iostream>
#include <algorithm>
#include <cstring>
#include <vector>
#include <cstdio>
#include <map>

using namespace std;

long long sum(long long n)
{
	return n * (n-1) / 2;
}

int main()
{
	int T;
	scanf("%d",&T);

	while(T--)
	{
		int M, N;
		scanf("%d%d",&M,&N);

		double ans = N / 2.0;

		long long h = 0;
		for(int i=0; i <= M; i++)
			h += sum(i) + sum(M-i);
		
		ans += h / ((double)M * M);
		printf("%.1f\n",ans);
	}
	return 0;
}