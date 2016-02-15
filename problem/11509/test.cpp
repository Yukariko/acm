// priorty_queue
#include <bits/stdc++.h>

using namespace std;

priority_queue<int> pq[1000001];

int main()
{
	int N;
	scanf("%d", &N);

	vector<int> a(N);
	int m = 0;
	for(int i=0; i < N; i++)
	{
		scanf("%d", &a[i]);
		m = max(m, a[i]);
	}

	for(int i=0; i < N; i++)
		pq[a[i]].push(i);

	int ans = 0;

	for(int i=m; i >= 1; i--)
	{
		while(!pq[i].empty())
		{
			int here = pq[i].top();
			pq[i].pop();

			int next = i - 1;
			while(!pq[next].empty() && pq[next].top() > here)
			{
				here = pq[next].top();
				pq[next].pop();
				next--;
			}

			ans++;
		}
	}

	printf("%d", ans);
	return 0;
}