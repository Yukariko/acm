#include <bits/stdc++.h>

using namespace std;

int main()
{
	int N;
	scanf("%d", &N);
	vector<int> a(N);
	vector<pair<int,int>> b(N);

	for(int i=0; i < N; i++)
	{
		scanf("%d", &a[i]);
		b[i].first = a[i];
		b[i].second = i;
	}

	sort(b.begin(), b.end());

	int ans = 0;
	for(int i=0; i < N; i++)
	{
		if(b[i].second != i)
		{
			int diffSum = 0;
			int diffCount = 0;
			int small = 0;
			int here = i;
			while(b[here].second != here)
			{
				diffCount++;
				diffSum += b[here].first;
				if(small == 0)
					small = b[here].first;

				swap(here, b[here].second);
			}
			diffSum += min((diffCount - 2) * small, b[0].first * (diffCount + 1) + small);
			ans += diffSum;
		}
	}
	printf("%d",ans);
	return 0;
}