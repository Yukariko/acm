#include <bits/stdc++.h>

using namespace std;

int lis(const vector<int>& a)
{
	vector<int> b;
	for(auto &pick : a)
	{
		auto lo = lower_bound(b.begin(), b.end(), pick);
		if(lo == b.end())
			b.push_back(pick);
		else
			*lo = pick;
	}
	return b.size();
}

int main()
{
	int T;
	scanf("%d", &T);

	for(int tc=1; tc <= T; tc++)
	{
		int N, K;
		scanf("%d%d", &N, &K);

		vector<int> a(N);
		for(int i=0; i < N; i++)
			scanf("%d", &a[i]);

		printf("Case #%d\n", tc);
		printf("%d\n", lis(a) >= K);
	}
	return 0;
}