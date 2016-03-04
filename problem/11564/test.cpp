#include <bits/stdc++.h>

using namespace std;

int main()
{
	long long K, A, B;
	scanf("%lld%lld%lld", &K, &A, &B);
	long long S = (A + K - 1) / K * K;
	if(A < 0)
		S = A / K * K; 
	if(B > S)
		printf("%lld", (B - S) / K + 1);
	else
		printf("0");
	return 0;
}