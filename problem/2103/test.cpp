#include <bits/stdc++.h>

using namespace std;

vector<int> mx[10001], my[10001];

int main()
{
	int N;
	scanf("%d", &N);

	vector<pair<int, int>> a(N);

	for(int i=0; i < N; i++)
	{
		scanf("%d%d", &a[i].first, &a[i].second);
		mx[a[i].first].push_back(a[i].second);
		my[a[i].second].push_back(a[i].first);
	}

	for(int i=0; i <= 10000; i++)
	{
		sort(mx[i].begin(), mx[i].end());
		sort(my[i].begin(), my[i].end());
	}

	int ans = 0;

	for(int i=0; i <= 10000; i++)
	{
		for(size_t j=1; j < my[i].size(); j+=2)
			ans += my[i][j] - my[i][j-1];
		for(size_t j=1; j < mx[i].size(); j+=2)
			ans += mx[i][j] - mx[i][j-1];
	}

	printf("%d", ans);
	return 0;
}