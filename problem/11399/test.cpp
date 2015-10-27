#include <bits/stdc++.h>

using namespace std;

int main()
{
	int N;
	scanf("%d",&N);

	vector<pair<int,int>> a(N);
	for(int i=0; i < N; i++)
	{
		scanf("%d",&a[i].first);
		a[i].second;
	}

	sort(a.begin(), a.end());

	int ans = 0;
	for(int i=0; i < N; i++)
		ans += a[i].first * (N - i);

	printf("%d",ans);
	return 0;
}