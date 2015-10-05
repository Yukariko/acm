#include <bits/stdc++.h>

using namespace std;

long long factorial(int N)
{
	if(N <= 1)
		return 1;
	return N * factorial(N-1);
}

int main()
{
	int N, K;
	scanf("%d%d",&N,&K);

	long long np = factorial(N);
	long long mp = factorial(N-K);
	long long kp = factorial(K);
	printf("%lld", np / kp / mp);
	return 0;
}