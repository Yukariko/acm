#include <bits/stdc++.h>

using namespace std;

int main()
{
	int N;
	scanf("%d", &N);

	vector<long long> a(N);
	for(int i=0; i < N; i++)
		scanf("%lld", &a[i]);

	sort(a.begin(), a.end());

	int msel = 0;
	int mcnt = 1;
	int cnt = 1;
	for(int i=1; i < N; i++)
	{
		if(a[i-1] != a[i])
		{
			cnt = 0;
		}
		cnt++;
		if(mcnt < cnt)
		{
			mcnt = cnt;
			msel = i;
		}
	}

	printf("%lld", a[msel]);
	return 0;
}