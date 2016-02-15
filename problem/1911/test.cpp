#include <bits/stdc++.h>

using namespace std;

int main()
{
	int N, L;
	scanf("%d%d", &N, &L);

	vector<pair<int, int>> a(N);
	for(int i=0; i < N; i++)
		scanf("%d%d", &a[i].first, &a[i].second);

	sort(a.begin(), a.end());

	int ans = 0;
	int covered = 0;

	for(int i=0; i < N; i++)
	{
		int l = a[i].first, r = a[i].second;

		l = max(l, covered);
		ans += (r - l + L - 1) / L;
		covered = l + (r - l + L - 1) / L * L;
	}

	printf("%d", ans);
	return 0;
}