#include <bits/stdc++.h>

using namespace std;

int main()
{
	int N, M;
	scanf("%d%d",&N,&M);

	vector<int> a(N), sum(N+1);

	for(int i=0; i < N; i++)
		scanf("%d",&a[i]);

	sum[0] = 0;
	for(int i=1; i <= N; i++)
		sum[i] = sum[i-1] + a[i-1];

	while(M--)
	{
		int l, r;
		scanf("%d%d",&l,&r);
		printf("%d\n", sum[r] - sum[l-1]);
	}
	return 0;
}