#include <bits/stdc++.h>

using namespace std;

int main()
{
	int N, M;
	scanf("%d%d", &N, &M);

	vector<vector<int>> a(N, vector<int>(M));
	for(int i=0; i < N; i++)
		for(int j=0; j < M; j++)
			scanf("%d", &a[i][j]);

	for(int i=0; i < N; i++)
		sort(a[i].begin(), a[i].end(), greater<int>());

	priority_queue<pair<int, int>> pq;
	int maxNum = 0;
	for(int i=0; i < N; i++)
	{
		maxNum = max(maxNum, a[i].back());
		pq.push({-a[i].back(), i});
		a[i].pop_back();
	}

	int ans = maxNum + pq.top().first;
	while(!pq.empty())
	{
		int here = -pq.top().first;
		int pos = pq.top().second;
		pq.pop();

		if(!a[pos].empty())
		{
			maxNum = max(maxNum, a[pos].back());
			pq.push({-a[pos].back(), pos});
			a[pos].pop_back();
		}
		else
			break;

		ans = min(ans, maxNum + pq.top().first);
	}

	printf("%d", ans);
	return 0;
}