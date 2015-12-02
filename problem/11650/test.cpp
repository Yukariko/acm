#include <bits/stdc++.h>

using namespace std;

int main()
{
	int N;
	scanf("%d",&N);

	vector<pair<int,int>> a(N);
	for(int i=0; i < N; i++)
		scanf("%d%d",&a[i].first, &a[i].second);

	sort(a.begin(), a.end());

	for(int i=0; i < N; i++)
		printf("%d %d\n", a[i].first, a[i].second);
	return 0;
}