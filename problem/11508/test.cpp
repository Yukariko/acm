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
	for(int i=0; i < N % 3; i++)
		ans += a[i];
	

	for(int i=N % 3; i < N; i+=3)
		ans += a[i+1] + a[i+2];
	
	printf("%lld", ans);
	return 0;
}