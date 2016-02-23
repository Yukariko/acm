#include <bits/stdc++.h>

using namespace std;

int main()
{
	int K, N;
	scanf("%d%d", &K, &N);

	vector<int> a(N);
	for(int i=0; i < N; i++)
		scanf("%d", &a[i]);

	vector<bool> tap(N+1, false);
	int count = 0;
	int ans = 0;
	int last;

	for(int i=0; i < N; i++)
	{
		if(tap[a[i]] == true)
			continue;

		if(count < K)
			count++;
		else if(i == N-1)
			ans++;
		else
		{
			vector<int> visit(N+1, 101);
			for(int j=0; j <= N; j++)
				if(!tap[j])
					visit[j] = -1;
			for(int j=i+1; j < N; j++)
				if(tap[a[j]] && visit[a[j]] == 101)
					visit[a[j]] = j;
			int sel = max_element(visit.begin(), visit.end()) - visit.begin();
			if(sel != 0)
				tap[sel] = false;
			else
				tap[last] = false;
			ans++;
		}
		tap[a[i]] = true;
		last = a[i];
	}

	printf("%d", ans);
	return 0;
}