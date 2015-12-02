#include <bits/stdc++.h>

using namespace std;

int main()
{
	int N;
	scanf("%d",&N);

	vector<pair<int,int>> a(N);
	for(int i=0; i < N; i++)
		scanf("%d%d",&a[i].second, &a[i].first);

	sort(a.begin(), a.end());

	for(int i=0; i < N; i++)
		printf("%d %d\n", a[i].second, a[i].first);
	return 0;
}