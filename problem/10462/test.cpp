#include <bits/stdc++.h>

using namespace std;

const int INF = 1 << 30;

vector<pair<int, int>> a;
int N;
int cache[6001];

int main()
{
	int p, q;
	while(~scanf("%d%d", &p, &q))
		a.push_back({q, p});
	N = a.size();

	sort(a.begin(), a.end());

	fill(&cache[0], &cache[N+1], INF);

	cache[0] = 0;
	cache[1] = a[0].second;

	for(int i=1; i < N; i++)
		for(int j=i+1; j; j--)
			if(cache[j-1] != INF && cache[j-1] + a[i].second <= a[i].first)
				cache[j] = min(cache[j], cache[j-1] + a[i].second);

	for(int i=N; i >= 0; i--)
		if(cache[i] != INF)
			return printf("%d", i), 0;
	return 0;
}