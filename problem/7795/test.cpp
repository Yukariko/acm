#include <bits/stdc++.h>

using namespace std;

int main()
{
	int T;
	scanf("%d",&T);

	while(T--)
	{
		int N, M;
		scanf("%d%d",&N,&M);

		vector<int> a(N), b(M);
		for(int i=0; i < N; i++)
			scanf("%d",&a[i]);

		for(int i=0; i < M; i++)
			scanf("%d",&b[i]);

		sort(b.begin(), b.end());

		int ans = 0;
		for(int i=0; i < N; i++)
			ans += lower_bound(b.begin(), b.end(), a[i]) - b.begin();

		printf("%d\n", ans);
	}
	return 0;
}