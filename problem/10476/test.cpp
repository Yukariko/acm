#include <bits/stdc++.h>

using namespace std;

int N, K;
int a[201][2];

int cache[201][4][201];

int solve(int pos, int state, int cnt)
{
	if(cnt < 0)
		return -987654321;
	if(pos == N)
	{
		if(cnt > 0)
			return -987654321;
		return 0;
	}

	int& ans = cache[pos][state][cnt];
	if(ans != -1)
		return ans;

	ans = a[pos][0] + a[pos][1] + solve(pos+1, 0, cnt);
	if(state == 0 || state == 1)
		ans = max(ans, a[pos][0] + solve(pos+1, 1, cnt-1));
	if(state == 0 || state == 2)
		ans = max(ans, a[pos][1] + solve(pos+1, 2, cnt-1));
	return ans;
}

int main()
{
	while(scanf("%d%d", &N, &K), N)
	{
		memset(cache, -1, sizeof(cache));
		for(int i=0; i < N; i++)
			scanf("%d%d", &a[i][0], &a[i][1]);

		printf("%d\n", solve(0, 0, K));
	}
	return 0;
}