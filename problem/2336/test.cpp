#include <bits/stdc++.h>

using namespace std;

const int MAX_N = 500001;
const int INF = 987654321;

int N;
int t[MAX_N * 2];

void modify(int pos, int val)
{
	for(t[pos += N] = val; pos > 1; pos >>= 1)
		t[pos >> 1] = min(t[pos], t[pos^1]);
}

int query(int left, int right)
{
	int res = INF;
	for(left += N, right += N; left < right; left >>= 1, right >>= 1)
	{
		if(left & 1)
			res = min(res, t[left++]);
		if(right & 1)
			res = min(res, t[--right]);
	}
	return res;
}

int main()
{
	scanf("%d", &N);

	fill(&t[0], &t[N * 2], INF);

	vector<int> a(N);
	vector<vector<int>> b(2, vector<int>(N+1));
	for(int i=0; i < N; i++)
		scanf("%d", &a[i]);

	for(int i=0; i < 2; i++)
	{
		for(int j=0; j < N; j++)
		{
			int n;
			scanf("%d", &n);
			b[i][n] = j + 1;
		}
	}

	int ans = 0;
	for(int i=0; i < N; i++)
	{
		int see = a[i];
		int second = b[0][see];
		int third = b[1][see];
		int check = query(1, second);
		if(third < check)
			ans++;
		modify(second, third);
	}

	printf("%d", ans);
	return 0;
}