// priority_queue
#include <bits/stdc++.h>

using namespace std;

bool cmp(const pair<int, int>& p, const pair<int, int>& q)
{
	if(p.first != q.first)
		return p.first < q.first;
	return p.second > q.second;
}

struct compare
{
	compare(){}
	bool operator()(const pair<int, int>& p, const pair<int, int>& q) const
	{
		return p.second > q.second;
	}
};

int main()
{
	int N;
	scanf("%d", &N);

	vector<pair<int, int>> a(N);
	for(int i=0; i < N; i++)
		scanf("%d%d", &a[i].first, &a[i].second);

	sort(a.begin(), a.end(), cmp);

	priority_queue<pair<int, int>, vector<pair<int, int>>, compare> q;
	q.push(a[0]);
	int ans = 1;
	for(int i=1; i < N; i++)
	{
		while(!q.empty() && q.top().second <= a[i].first)
			q.pop();
		q.push(a[i]);
		ans = max(ans, (int)q.size());
	}

	printf("%d", ans);
	return 0;
}