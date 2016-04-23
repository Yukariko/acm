#include <bits/stdc++.h>

using namespace std;

int main()
{
	int N, M;
	scanf("%d%d", &N, &M);

	vector<vector<int>> a(N+1);
	vector<pair<int, pair<int, int>>> b(M+1);
	for(int i=1; i <= M; i++)
	{
		int l, r, w;
		scanf("%d%d%d", &l, &r, &w);
		b[i] = {l, {r, w}};
		a[l].push_back(i);
		a[r].push_back(-i);
	}

	priority_queue<pair<int, int>> pq;

	vector<bool> del(M, false);

	for(int i=1; i <= N; i++)
	{
		for(int j=0; j < a[i].size(); j++)
			if(a[i][j] > 0)
				pq.push({b[a[i][j]].second.second + N - i, a[i][j]});

		while(!pq.empty() && del[pq.top().second])
			pq.pop();

		if(pq.empty())
			printf("0 ");
		else
			printf("%d ", b[pq.top().second].second.second + i - b[pq.top().second].first);

		for(int j=0; j < a[i].size(); j++)
			if(a[i][j] < 0)
				del[-a[i][j]] = true;
	}

	return 0;
}