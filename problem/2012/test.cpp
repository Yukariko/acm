#include <bits/stdc++.h>

using namespace std;

int main()
{
	int N;
	scanf("%d", &N);

	vector<int> a(N);
	for(int i=0; i < N; i++)
		scanf("%d", &a[i]);

	sort(a.begin(), a.end());

	long long ans = 0;
	for(int i=0; i < N; i++)
		ans += abs(a[i] - (i + 1));

	printf("%lld", ans);
	return 0;
}