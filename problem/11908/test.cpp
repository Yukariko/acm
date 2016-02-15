#include <bits/stdc++.h>

using namespace std;

int main()
{
	int N;
	scanf("%d", &N);

	int ans = 0;
	int M = 0;
	for(int i=0; i < N; i++)
	{
		int n;
		scanf("%d", &n);
		ans += n;
		M = max(M, n);
	}

	ans -= M;
	printf("%d", ans);
	return 0;
}