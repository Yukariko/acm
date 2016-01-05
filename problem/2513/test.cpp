#include <bits/stdc++.h>

using namespace std;

int main()
{
	int N, K, S;
	scanf("%d%d%d",&N,&K,&S);

	vector<pair<int,int>> a(N);
	for(int i=0; i < N; i++)
		scanf("%d%d", &a[i].first, &a[i].second);

	sort(a.begin(), a.end());

	int pos = 0;
	while(pos < N && a[pos].first <= S)
		pos++;
	pos--;

	int ans = 0;
	int here = S;
	int nride = 0;

	int total = 0;
	for(int i=0; i <= pos; i++)
		total += a[i].second;

	for(int i=pos; i >= 0; i--)
	{
		total -= a[i].second;
		while(a[i].second)
		{
			ans += here - a[i].first;
			here = a[i].first;
			
			int pick = min(a[i].second, K - nride);
			nride += pick;
			a[i].second -= pick;

			if(nride == K)
			{
				nride = 0;
				ans += S - here;
				here = S;
			}
		}

		if(i && (total + nride) > K && (total + nride + K - 1) / K != (total + K - 1) / K)
		{
			nride = 0;
			ans += S - here;
			here = S;
		}
	}
	ans += S - here;
	here = S;
	nride = 0;

	total = 0;
	for(int i=pos+1; i < N; i++)
		total += a[i].second;

	for(int i=pos+1; i < N; i++)
	{
		total -= a[i].second;
		while(a[i].second)
		{
			ans += a[i].first - here;
			here = a[i].first;
			
			int pick = min(a[i].second, K - nride);
			nride += pick;
			a[i].second -= pick;

			if(nride == K)
			{
				nride = 0;
				ans += here - S;
				here = S;
			}
		}

		if(i != N-1 && (total + nride) > K && (total + nride + K - 1) / K != (total + K - 1) / K)
		{
			nride = 0;
			ans += here - S;
			here = S;
		}
	}
	ans += here - S;

	printf("%d",ans);
	return 0;
}