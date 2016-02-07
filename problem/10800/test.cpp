#include <bits/stdc++.h>

using namespace std;

int main()
{
	int N;
	scanf("%d", &N);

	vector<pair<int, int>> a[2001];
	for(int i=0; i < N; i++)
	{
		int color, num;
		scanf("%d%d", &color, &num);
		a[num].push_back({color, i});
	}

	vector<int> c(N+1, 0);
	vector<int> ans(N, 0);

	long long sum = 0;
	for(int i=2; i <= 2000; i++)
	{
		sum += a[i-1].size() * (i-1);
		for(int j=0; j < a[i-1].size(); j++)
			c[a[i-1][j].first] += i-1;
		for(int j=0; j < a[i].size(); j++)
			ans[a[i][j].second] = sum - c[a[i][j].first];
	}

	for(int i=0; i < N; i++)
		printf("%d\n", ans[i]);
	return 0;
}