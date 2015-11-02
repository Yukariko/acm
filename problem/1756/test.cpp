#include <bits/stdc++.h>

using namespace std;

int main()
{
	int N, M;
	scanf("%d%d",&N,&M);

	vector<int> a(N);
	scanf("%d",&a[0]);
	a[0] = -a[0];
	for(int i=1; i < N; i++)
	{
		scanf("%d",&a[i]);
		a[i] = -min(-a[i-1], a[i]);
	}

	while(M--)
	{
		int n;
		scanf("%d",&n);
		N = upper_bound(a.begin(), a.begin() + N, -n) - a.begin() - 1;
	}

	printf("%d",N + 1);
	return 0;
}