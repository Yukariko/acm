#include <bits/stdc++.h>

using namespace std;

const int INF = 987654321;

int N;
int a[100001];
int check[100001];

int solve(int pos)
{
	int& ans = check[pos];
	if(ans == -1)
		return -INF;

	if(pos == a[pos])
	{
		ans = -1;
		return 0;
	}

	int plus = ans == 0;

	if(++ans == 3)
		return 0;

	plus = plus + solve(a[pos]);
	ans = -1;
	return plus;
}

int main()
{
	int T;
	scanf("%d", &T);

	while(T--)
	{
		scanf("%d", &N);
		for(int i=1; i <= N; i++)
			scanf("%d", &a[i]);

		memset(check, -1, sizeof(check));

		int ans = 0;

		int idx = 0;
		for(int i=1; i <= N; i++)
		{
			if(check[i] != -1)
				continue;

			int pos = i;
			int start = idx;
			while(1)
			{
				if(check[pos] != -1)
				{
					if(start <= check[pos])
						ans += check[pos] - start;
					else
						ans += idx - start;
					break;
				}

				check[pos] = idx++;
				pos = a[pos];
			}

		}

		printf("%d\n", ans);
	}
	return 0;
}