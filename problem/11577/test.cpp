#include <bits/stdc++.h>

using namespace std;

int main()
{
	int N, K;
	scanf("%d%d", &N, &K);

	vector<int> a(N);
	for(int i=0; i < N; i++)
		scanf("%d", &a[i]);

	vector<bool> turn(N, false);
	int ans = 0, k = 0;
	for(int i=0; i <= N-K; i++)
	{
		k -= turn[i];
		if((a[i] + k) % 2)
		{
			k++;
			turn[i + K] = true;
			ans++;
		}
	}

	for(int i=N-K+1; i < N; i++)
	{
		k -= turn[i];
		if((a[i] + k) % 2)
		{
			puts("Insomnia");
			return 0;
		}
	}

	printf("%d", ans);
	return 0;
}