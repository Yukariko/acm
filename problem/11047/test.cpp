#include <bits/stdc++.h>

using namespace std;

int main()
{
	int N, K;
	scanf("%d%d",&N,&K);

	vector<int> a(N);
	for(int i=0; i < N; i++)
		scanf("%d",&a[i]);

	int ans = 0;
	for(int i=N-1; i >= 0; i--)
	{
		ans += K / a[i];
		K -= K / a[i] * a[i];
	}
	printf("%d",ans);
	return 0;
}