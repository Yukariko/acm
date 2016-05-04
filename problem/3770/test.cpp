#include <bits/stdc++.h>

using namespace std;

const int MAX_N = 1001;

int N, M, K;
vector<pair<int, int>> a;

long long t[MAX_N * 2];

void modify(int pos, long long val)
{
	for(t[pos += M] += val; pos > 1; pos >>= 1)
		t[pos>>1] = t[pos] + t[pos^1];
}

long long query(int l, int r)
{
	long long res = 0;
	for(l += M, r += M; l < r; l >>= 1, r >>= 1)
	{
		if(l & 1)
			res += t[l++];
		if(r & 1)
			res += t[--r];
	}
	return res;
}

int main()
{
	int T;
	scanf("%d", &T);

	for(int tc=1; tc <= T; tc++)
	{
		scanf("%d%d%d", &N, &M, &K);
		a.clear();
		a.resize(K);
		for(int i=0; i < K; i++)
			scanf("%d%d", &a[i].first, &a[i].second);

		memset(t, 0, sizeof(t));
		sort(a.begin(), a.end());

		long long ans = 0;
		for(int i=0; i < K; i++)
		{
			ans += query(a[i].second, M);
			modify(a[i].second - 1, 1);
		}

		printf("Test case %d: %lld\n", tc, ans);
	}
	return 0;
}