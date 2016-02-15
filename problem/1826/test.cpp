// priority_queue
#include <bits/stdc++.h>

using namespace std;

int main()
{
	int N;
	scanf("%d", &N);

	vector<pair<int, int>> a(N+1);
	for(int i=0; i < N; i++)
		scanf("%d%d", &a[i].first, &a[i].second);

	int L, P;
	scanf("%d%d", &L, &P);

	a[N] = {L, 0};

	sort(a.begin(), a.end());

	priority_queue<int> pq;
	int ans = 0;
	int pos = 0;
	for(int i=0; i <= N; i++)
	{
		while(!pq.empty() && a[i].first - pos > P)
		{
			P += pq.top();
			pq.pop();
			ans++;
		}
		if(a[i].first - pos > P)
		{
			puts("-1");
			return 0;
		}
		P -= a[i].first - pos;
		pos = a[i].first;
		pq.push(a[i].second);
	}

	printf("%d", ans);
	return 0;
}