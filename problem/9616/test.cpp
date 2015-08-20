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

	while(scanf("%d%d",&N,&M), N)
	{
		long long ans = 0;

		int minNM = min(N, M);
		for(int i=1; i <= minNM; i+=2)
			ans += 1LL * i * (N - i+1) * (M - i+1);

		printf("%lld\n",ans);
	}
	return 0;
}