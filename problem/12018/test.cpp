#include <bits/stdc++.h>

using namespace std;

int main()
{
	int N, M;
	scanf("%d%d", &N, &M);

	vector<int> b(N);

	for(int i=0; i < N; i++)
	{
		int P, L;
		scanf("%d%d", &P, &L);

		vector<int> a(P);
		for(int j=0; j < P; j++)
			scanf("%d", &a[j]);
		
		if(P < L)
		{
			b[i] = 1;
			continue;
		}

		sort(a.begin(), a.end());
		b[i] = a[P - L];
	}

	sort(b.begin(), b.end());

	int ans = 0;
	for(int i=0; i < N; i++)
		if(b[i] <= M)
			ans++, M -= b[i];

	printf("%d", ans);
	return 0;
}