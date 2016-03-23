#include <bits/stdc++.h>

using namespace std;

const int MOD = 987654321;

int main()
{
	int N;
	scanf("%d", &N);
 
	vector<int> a(N+1, 0);
	a[0] = 1;
	for(int i=2; i <= N; i+=2)
		for(int j=i; j >= 2; j-=2)
			a[i] = (a[i] + 1LL * a[j-2] * a[i-j]) % MOD;

	printf("%d", a[N]);
	return 0;
}