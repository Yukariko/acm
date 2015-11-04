#include <bits/stdc++.h>

using namespace std;

int main()
{
	int T;
	scanf("%d",&T);

	while(T--)
	{
		long long A, B;
		scanf("%lld%lld",&A,&B);
		printf("%lld\n", (A * A) / (B * B));
	}
	return 0;
}