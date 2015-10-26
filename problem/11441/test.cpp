#include <bits/stdc++.h>

using namespace std;

int main()
{
	int N;
	scanf("%d",&N);

	vector<int> a(N);
	for(int i=0; i < N; i++)
		scanf("%d",&a[i]);

	vector<int> sum(N+1);
	sum[0] = 0;
	for(int i=0; i < N; i++)
		sum[i+1] = sum[i] + a[i];

	int M;
	scanf("%d",&M);
	while(M--)
	{
		int l, r;
		scanf("%d%d",&l,&r);
		printf("%d\n", sum[r] - sum[l-1]);
	}
	return 0;
}