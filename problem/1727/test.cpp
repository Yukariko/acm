#include <bits/stdc++.h>

using namespace std;

const int INF = 987654321;

int N, M;
int a[1001];
int b[1001];

int cache[1001][1001];

int solve(int apos, int bpos)
{
	if(bpos == M)
		return 0;
	if(apos == N)
		return INF;

	int& ans = cache[apos][bpos];
	if(ans != -1)
		return ans;

	ans = min(solve(apos + 1, bpos), abs(a[apos] - b[bpos]) + solve(apos + 1, bpos + 1));
	return ans;
}

int main()
{
	memset(cache, -1, sizeof(cache));
	scanf("%d%d", &N, &M);
	for(int i=0; i < N; i++)
		scanf("%d", &a[i]);
	for(int i=0; i < M; i++)
		scanf("%d", &b[i]);

	sort(a, a + N);
	sort(b, b + M);

	if(N < M)
	{
		swap(N, M);
		swap(a, b);
	}

	printf("%d", solve(0, 0));
	return 0;
}