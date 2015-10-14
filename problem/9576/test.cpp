#include <bits/stdc++.h>

using namespace std;

bool cmp(const pair<int,int>& p, const pair<int,int>& q)
{
	if(p.second != q.second)
		return p.second < q.second;
	return p.first < q.first;
}

int main()
{
	int T;
	scanf("%d",&T);
	while(T--)
	{
		int N, M;
		scanf("%d%d",&N,&M);

		vector< pair<int, int> > a(M);
		for(int i=0; i < M; i++)
			scanf("%d%d",&a[i].first, &a[i].second);

		sort(a.begin(), a.end(), cmp);

		int ans = 0;
		bool b[1001] = {};
		for(int i=0; i < M; i++)
			for(int j=a[i].first; j <= a[i].second; j++)
				if(b[j] == false)
				{
					ans++;
					b[j] = true;
					break;
				}
		printf("%d\n",ans);
	}
	return 0;
}