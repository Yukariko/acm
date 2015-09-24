#include <iostream>
#include <algorithm>
#include <cstring>
#include <vector>
#include <cstdio>
#include <map>

using namespace std;

int main()
{
	int N, M;
	scanf("%d%d",&N,&M);

	int a[1001]={};
	int psum = 0;

	a[0] = 1;
	for(int i=0; i < N; i++)
	{
		int n;
		scanf("%d",&n);
		psum = (n + psum) % M;
		a[psum]++;
	}

	long long ans = 0;
	for(int i=0; i < M; i++)
		ans += (long long)a[i] * (a[i]-1) / 2;

	printf("%lld",ans);
	return 0;
}