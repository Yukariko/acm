#include <bits/stdc++.h>

using namespace std;

int main()
{
	int N;
	scanf("%d",&N);

	long long ans = 0;
	int last;
	scanf("%d",&last);

	for(int i=1; i < N; i++)
	{
		int n;
		scanf("%d",&n);
		ans += max(last, n);
		last = n;
	}
	printf("%lld",ans);
	return 0;
}