#include <bits/stdc++.h>

using namespace std;

int main()
{
	int N, M, L;
	scanf("%d%d%d", &N, &M, &L);

	vector<int> a(N+1);
	for(int i=0; i < N; i++)
		scanf("%d", &a[i]);

	vector<pair<int, int>> b(M);
	for(int i=0; i < M; i++)
		scanf("%d%d", &b[i].first, &b[i].second);

	sort(a.begin(), a.begin() + N);
	sort(b.begin(), b.end());

	a[N] = b[M-1].first+1;

	int ans = 0;
	int bpos = 0;
	for(int i=0; i < N; i++)
	{
		while(bpos < M && b[bpos].first <= a[i])
		{
			if(abs(b[bpos].first - a[i]) + b[bpos].second <= L)
			{
				b[bpos].second = L+1;
				ans++;
			}
			bpos++;
		}

		for(int j=bpos; j < M && b[j].first < a[i+1]; j++)
			if(abs(b[j].first - a[i]) + b[j].second <= L)
				b[j].second = L+1,	ans++;
	}

	printf("%d", ans);
	return 0;
}