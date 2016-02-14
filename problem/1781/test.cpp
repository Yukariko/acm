#include <bits/stdc++.h>

using namespace std;

int main()
{
	int N;
	scanf("%d", &N);

	vector<pair<int, int>> a(N);

	for(int i=0; i < N; i++)
		scanf("%d%d", &a[i].first, &a[i].second);

	sort(a.begin(), a.end());

	priority_queue<int> select;

	for(int i=0; i < N; i++)
	{
		if(select.size() < a[i].first)
			select.push(-a[i].second);

		else if(a[i].first == select.size() && -select.top() < a[i].second)
		{
			select.pop();
			select.push(-a[i].second);
		}
	}

	int ans = 0;
	while(!select.empty())
	{
		ans += -select.top();
		select.pop();
	}

	printf("%d", ans);
	return 0;
}