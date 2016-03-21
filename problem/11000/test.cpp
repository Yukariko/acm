#include <bits/stdc++.h>

using namespace std;

int main()
{
	int N;
	scanf("%d", &N);

	vector<pair<int, int>> a(N*2);
	for(int i=0; i < N; i++)
	{
		int p, q;
		scanf("%d%d", &p, &q);
		a[i*2] = {p, 1};
		a[i*2 + 1] = {q, -1};
	}

	sort(a.begin(), a.end());

	int ans = 0;
	int cur = 0;
	for(size_t i=0; i < a.size(); i++)
	{
		cur += a[i].second;
		ans = max(ans, cur);
	}

	printf("%d", ans);
	return 0;
}