#include <bits/stdc++.h>

using namespace std;

int main()
{
	int N, K;
	scanf("%d%d", &N, &K);

	vector<pair<int, int>> a(N);
	for(int i=0; i < N; i++)
		scanf("%d%d", &a[i].first, &a[i].second);

	vector<int> b(K);
	for(int i=0; i < K; i++)
		scanf("%d", &b[i]);

	sort(a.begin(), a.end());
	sort(b.begin(), b.end());

	long long ans = 0;
	int apos = 0;

	priority_queue<int> pq;
	for(int i=0; i < K; i++)
	{
		while(apos < N && a[apos].first <= b[i])
			pq.push(a[apos++].second);
		if(!pq.empty())
		{
			ans += pq.top();
			pq.pop();
		}
	}

	printf("%lld", ans);
	return 0;
}