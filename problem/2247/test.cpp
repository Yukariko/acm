#include <bits/stdc++.h>

using namespace std;

const int MOD = 1000000;

int main()
{
	int N;
	scanf("%d", &N);

	int ans = 0;
	for(int i=2; i < N; i++)
		ans = (ans + N / i * i - i) % MOD;

	printf("%d", ans);
	return 0;
}