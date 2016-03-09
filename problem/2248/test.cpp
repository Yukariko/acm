#include <bits/stdc++.h>

using namespace std;

int N, L;
long long K;

int sel[32];
long long cache[32][32];

long long solve(int pos, int cnt)
{
	if(cnt > L)
		return 0;
	if(pos == N)
	{
		if(--K == 0)
		{
			for(int i=0; i < N; i++)
				printf("%d", sel[i]);
			exit(0);
		}
		return 1;
	}

	long long& ans = cache[pos][cnt];
	if(ans != -1 && ans < K)
	{
		K -= ans;
		return ans;
	}

	sel[pos] = 0;
	ans = solve(pos + 1, cnt);
	sel[pos] = 1;
	ans += solve(pos + 1, cnt + 1);
	return ans;
}

int main()
{
	memset(cache, -1, sizeof(cache));
	scanf("%d%d%lld", &N, &L, &K);
	solve(0, 0);
	return 0;
}