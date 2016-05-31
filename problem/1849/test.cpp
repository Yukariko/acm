#include <bits/stdc++.h>

using namespace std;

int N;

const int INF = 987654321;
const int MAX_N = 100000;
int t[2 * MAX_N];

void build()
{
	for(int pos=N-1; pos > 0; pos--)
		t[pos] = t[pos<<1] + t[pos<<1|1];
}

void modify(int pos, int val)
{
	for(t[pos += N] = val; pos > 1; pos >>= 1)
		t[pos >> 1] = t[pos] + t[pos^1];
}

int query(int l, int r)
{
	int ans = 0;
	for(l += N, r += N; l < r; l >>= 1, r >>= 1)
	{
		if(l & 1)
			ans += t[l++];
		if(r & 1)
			ans += t[--r];
	}
	return ans;
}

int main()
{
	scanf("%d", &N);

	vector<int> a(N);
	for(int i=0; i < N; i++)
		scanf("%d", &a[i]);

	for(int i=0; i < N; i++)
		t[i + N] = 1;

	build();

	vector<int> ans(N);
	for(int i=0; i < N; i++)
	{
		int sel;
		int l=1, r=N;
		while(l <= r)
		{
			int m = (l + r) / 2;
		 	if(query(0, m) <= a[i])
		 		l = m + 1;
		 	else
		 		r = m - 1;
		}
		sel = l - 1;
		ans[sel] = i + 1;
		modify(sel, 0);
	}

	for(int i=0; i < N; i++)
		printf("%d\n", ans[i]);

	return 0;
}