#include <bits/stdc++.h>

using namespace std;

int main()
{
	int N, M, K;
	scanf("%d%d%d", &N, &M, &K);

	vector<int> a(N);
	for(int i=0; i < N; i++)
		scanf("%d", &a[i]);

	sort(a.begin(), a.end());

	int ans = 0;
	M *= K;
	for(int i=N-1; i >= 0 && M > 0; i--)
	{
		M -= a[i];
		ans++;
	}

	if(M > 0)
		puts("STRESS");
	else
		printf("%d", ans);
	return 0;
}