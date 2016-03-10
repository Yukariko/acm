#include <bits/stdc++.h>

using namespace std;

int N;
int X[100001];
int Y[100001];

long long cache[100001][5];

const int dy[] = {0, 1, -1, 0, 0};
const int dx[] = {0, 0, 0, 1, -1};

long long solve(int pos, int d)
{
	if(pos == N-1)
		return 0;

	long long& ans = cache[pos][d];
	if(ans != -1)
		return ans;

	ans = 100000LL * 100001;

	int y = Y[pos] + dy[d];
	int x = X[pos] + dx[d];

	for(int i=0; i < 5; i++)
	{
		int ny = Y[pos+1] + dy[i];
		int nx = X[pos+1] + dx[i];
		if(ny < 0 || ny > 100000 || nx < 0 || nx > 100000)
			continue;

		ans = min(ans, abs(ny - y) + abs(nx - x) + solve(pos + 1, i));
	}

	return ans;
}

int main()
{
	memset(cache, -1, sizeof(cache));
	scanf("%d", &N);
	N++;
	for(int i=0; i < N; i++)
		scanf("%d%d", &X[i], &Y[i]);

	printf("%lld", solve(0, 0));
	return 0;
}