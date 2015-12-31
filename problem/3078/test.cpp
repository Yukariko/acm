#include <bits/stdc++.h>

using namespace std;

int main()
{
	int N, K;
	scanf("%d%d",&N,&K);

	int a[21] = {};

	vector<int> b(N);

	long long ans = 0;

	for(int i=0; i < N; i++)
	{
		char name[21];
		scanf("%s", name);
		b[i] = strlen(name);

		ans += a[b[i]]++;
		if(i >= K)
			a[b[i-K]]--;
	}

	printf("%lld",ans);

	return 0;
}