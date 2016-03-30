#include <bits/stdc++.h>

using namespace std;

int main()
{
	int N, K;
	scanf("%d%d", &N, &K);

	vector<int> a(N);
	for(int i=0; i < N; i++)
		scanf("%d", &a[i]);

	vector<int> sum(N+1);
	sum[0] = a[0];
	for(int i=1; i < N; i++)
		sum[i] = sum[i-1] + a[i];

	map<int, int> check;
	check[0] = 1;
	
	long long ans = 0;
	for(int i=0; i < N; i++)
	{
		ans += check[K - sum[i]];
		check[-sum[i]]++;
	}

	printf("%lld", ans);
	return 0;
}