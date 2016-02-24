#include <bits/stdc++.h>

using namespace std;

int N;
int a[1001];
int b[1001];

const int INF = 987654321;
const int tok = 100000;
int d[2][200001];

int idx(int n)
{
	return n + tok;
}

int main()
{
	int T;
	scanf("%d", &T);

	while(T--)
	{
		scanf("%d", &N);
		for(int i=0; i < N; i++)
			scanf("%d%d", &a[i], &b[i]);

		memset(d, 0x70, sizeof(d));

		int range = max(a[0], b[0]);

		d[0][idx(a[0])] = a[0];
		d[0][idx(-b[0])] = b[0];

		for(int i=1; i < N; i++)
		{
			range += max(a[i], b[i]);
			int here = i & 1;
			int there = i & 1 ^ 1;

			for(int j=-range; j <= range; j++)
			{
				int anum = INF;
				if(j - a[i] >= -range)
				{
					if(j <= 0)
						anum = d[there][idx(j - a[i])];
					else if(j - a[i] >= 0)
						anum = d[there][idx(j - a[i])] + a[i];
					else
						anum = d[there][idx(j - a[i])] + j;
				}
				int bnum = INF;
				if(j + b[i] <= range)
				{
					if(j >= 0)
						bnum = d[there][idx(j + b[i])];
					else if(j + b[i] <= 0)
						bnum = d[there][idx(j + b[i])] + b[i];
					else
						bnum = d[there][idx(j + b[i])] - j;
				}
				d[here][idx(j)] = min(anum, bnum);
			}
		}

		int ans = INF;
		for(int i=-range; i <= range; i++)
			if(ans > d[N&1^1][idx(i)])
				ans = d[N&1^1][idx(i)];
		printf("%d\n", ans);
	}
	return 0;
}