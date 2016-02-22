#include <bits/stdc++.h>

using namespace std;

int main()
{
	int N;
	scanf("%d", &N);

	vector<pair<int, pair<int, int>>> a(3 * N);
	for(int i=0; i < 3 * N; i++)
	{
		scanf("%d%d", &a[i].first, &a[i].second.first);
		a[i].second.second = i + 1;
	}

	sort(a.begin(), a.end());

	for(int i=0; i < 3 * N; i+=3)
		printf("%d %d %d\n", a[i].second.second, a[i+1].second.second, a[i+2].second.second);

	return 0;
}