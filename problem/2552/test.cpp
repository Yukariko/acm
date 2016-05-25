#include <bits/stdc++.h>

using namespace std;

int N, K;
int a[31];
int b[31];

int cache[31][31];

int solve(int pos, int maxCon, int bin)
{
	if(pos == N)
	{
		if(--K == 0)
		{
			printf("%d", bin);
			exit(0);
		}
		return 1;
	}

	int& ans = cache[pos][maxCon];
	if(ans != -1 && ans < K)
	{
		K -= ans;
		return ans;
	}

	ans = solve(pos + 1, maxCon, bin * 2);
	if(maxCon < a[pos])
		ans += solve(pos + 1, a[pos], bin * 2 + 1);
	return ans;
}


int main()
{
	scanf("%d", &N);
	for(int i=0; i < N; i++)
		scanf("%d", &a[i]);
	scanf("%d", &K);

	memset(cache, -1, sizeof(cache));
	solve(0, 0, 0);
	puts("-1");
	return 0;
}