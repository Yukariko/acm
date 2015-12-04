#include <bits/stdc++.h>

using namespace std;

int main()
{
	int N, M;
	scanf("%d%d",&N,&M);

	vector<priority_queue<int>> a(6);

	int ans = 0;
	for(int i=0; i < N; i++)
	{
		int p, q;
		scanf("%d%d",&p,&q);
		p--;
		while(!a[p].empty() && a[p].top() > q)
		{
			ans++;
			a[p].pop();
		}
		if(a[p].empty() || a[p].top() < q)
		{
			ans++;
			a[p].push(q);
		}
	}

	printf("%d",ans);
	return 0;
}