#include <bits/stdc++.h>

using namespace std;

const int INF = 987654321;

int N, K;
int five[100001];
int two[100001];

int cache[100001];
int cache2[100001];

int solve(int pos)
{
	if(pos == N-1)
		return 0;

	int& ans = cache[pos];
	if(ans != -1)
		return ans;

	ans = INF;
	for(int i=1; i <= K && i + pos < N; i++)
		ans = min(ans, five[i + pos] + solve(i + pos));
	return ans;
}

int solve2(int pos)
{
	if(pos == N-1)
		return 0;

	int& ans = cache2[pos];
	if(ans != -1)
		return ans;

	ans = INF;
	for(int i=1; i <= K && i + pos < N; i++)
		ans = min(ans, two[i + pos] + solve2(i + pos));
	return ans;
}

int main()
{
	int T;
	scanf("%d", &T);

	while(T--)
	{
		scanf("%d%d", &N, &K);
		for(int i=0; i < N; i++)
		{
			int n;
			scanf("%d", &n);
			five[i] = two[i] = 0;
			while(n % 5 == 0)
			{
				five[i]++;
				n /= 5;
			}

			while(n % 2 == 0)
			{
				two[i]++;
				n /= 2;
			}
		}

		memset(cache, -1, sizeof(cache));
		memset(cache2, -1, sizeof(cache2));

		printf("%d\n", min(five[0] + solve(0), two[0] + solve2(0)));
	}
	return 0;
}