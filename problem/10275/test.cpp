#include <bits/stdc++.h>

using namespace std;

int main()
{
	int T;
	scanf("%d",&T);

	while(T--)
	{
		long long N, A, B;
		scanf("%lld%lld%lld",&N,&A,&B);
		printf("%d\n", __builtin_popcountll(A | B));
	}
	return 0;
}