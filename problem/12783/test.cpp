#include <bits/stdc++.h>

using namespace std;

const int MAX_N = 1000000;
const int INF = 987654321;

int N, _mask;
int a[11];
int visit[1000001];

int solve(int num)
{
	int& ans = visit[num];
	if(ans != -1)
		return ans;

	int mask = 0;
	for(int n=num; n; n/=10)
		mask |= 1 << (n % 10);

	if((_mask & mask) == mask)
		return ans = 0;

	ans = INF;
	for(int i=2; i * i <= num; i++)
		if(num % i == 0)
			ans = min(ans, 1 + solve(i) + solve(num / i));
	return ans;
}

int main()
{
	int T;
	scanf("%d", &T);

	while(T--)
	{
		_mask = 0;
		scanf("%d", &N);
		for(int i=0; i < N; i++)
		{
			scanf("%d", &a[i]);
			_mask |= 1 << a[i];
		}

		memset(visit, -1, sizeof(visit));

		int M;
		scanf("%d", &M);

		while(M--)
		{
			int n;
			scanf("%d", &n);
			int ans = solve(n);
			printf("%d\n", ans == INF? -1: ans);
		}
	}

	return 0;
}