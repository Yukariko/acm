#include <bits/stdc++.h>

using namespace std;

const int INF = 987654321;

int N, M;
int a[101];
int cache[101][101];

int solve(int pos, int cnt)
{
	if(pos >= N)
		return cnt == 0? 0: -INF + 1;

	int& ans = cache[pos][cnt];
	if(ans != -INF)
		return ans;

	ans = solve(pos + 1, cnt);
	if(cnt == 0)
		return ans;

	int sum = 0;
	for(int i=pos; i < N; i++)
	{
		sum += a[i];
		ans = max(ans, sum + solve(i + 2, cnt - 1));
	}
	return ans;
}

int main()
{
	scanf("%d%d", &N, &M);
	for(int i=0; i < N; i++)
		for(int j=0; j <= M; j++)
			cache[i][j] = -INF;

	for(int i=0; i < N; i++)
		scanf("%d", &a[i]);

	printf("%d", solve(0, M));
	return 0;
}