#include <bits/stdc++.h>

using namespace std;

const int INF = 987654321;

int N;
bool adj[257][257];

int cache[257][257][257];

int solve(int pos, int asc, int desc)
{
	if(pos == N+1)
	{
		if(asc < desc || (asc != N && desc != N) || !adj[asc][desc])
			return -INF;
		return 0;
	}

	int& ans = cache[pos][asc][desc];
	if(ans != -1)
		return ans;

	ans = solve(pos + 1, asc, desc);
	if(adj[asc][pos])
		ans = max(ans, 1 + solve(pos + 1, pos, desc));
	if(adj[desc][pos])
		ans = max(ans, 1 + solve(pos + 1, asc, pos));

	return ans;
}

void construct(int pos, int asc, int desc)
{
	if(pos == N)
	{
		printf("%d ", N);
		return;
	}

	int ans = cache[pos][asc][desc];
	if(ans == cache[pos+1][asc][desc])
	{
		construct(pos + 1, asc, desc);
	}
	else if(adj[asc][pos] && ans == 1 + cache[pos+1][pos][desc])
	{
		printf("%d ", pos);
		construct(pos + 1, pos, desc);
	}
	else if(adj[desc][pos] && ans == 1 + cache[pos+1][asc][pos])
	{
		construct(pos + 1, asc, pos);
		printf("%d ", pos);
	}
}

int main()
{
	memset(cache, -1, sizeof(cache));
	scanf("%d", &N);

	int u, v;
	while(scanf("%d%d", &u, &v), u)
	{
		adj[u][v] = true;
		adj[v][u] = true;
	}

	int ans = solve(1, 1, 1);
	if(ans < 0)
		puts("0");
	else
	{
		printf("%d\n", 1 + ans);
		printf("1 ");
		construct(1, 1, 1);
		printf("1\n");
	}
	return 0;
}