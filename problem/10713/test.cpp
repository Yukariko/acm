#include <bits/stdc++.h>

using namespace std;

int main()
{
	int N, M;
	scanf("%d%d",&N,&M);

	vector<int> a(M);
	for(int i=0; i < M; i++)
		scanf("%d",&a[i]);

	vector<int> A(N), B(N), C(N);
	for(int i=0; i < N; i++)
		scanf("%d%d%d",&A[i],&B[i],&C[i]);

	vector<int> open(N+1, 0), close(N+1, 0);
	for(size_t i=1; i < M; i++)
	{
		open[min(a[i],a[i-1])]++;
		close[max(a[i],a[i-1])]++;
	}

	int left = 0;
	int right = 0;
	long long ans = 0;
	long long count = 0;

	for(int i=0; i < N-1; i++)
	{
		count += open[i+1];
		ans += min(A[i] * count, C[i] + B[i] * count);
		if(i == 0)
			count -= close[i+1];
		count -= close[i+2];
	}

	printf("%lld", ans);
	return 0;
}