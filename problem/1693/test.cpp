#include <bits/stdc++.h>

using namespace std;

vector<vector<int>> a;

bool visit[100001];
int cache[100001][10];

int solve(int pos, int color)
{
	int& ans = cache[pos][color];
	if(ans != -1)
		return ans;

	visit[pos] = true;
	
	ans = color;
	for(int i=0; i < a[pos].size(); i++)
	{
		if(visit[a[pos][i]])
			continue;
		int choose = 987654321;
		for(int j=1; j <= 9; j++)
			if(j != color)
				choose = min(choose, solve(a[pos][i], j));
		ans += choose;
	}
	
	visit[pos] = false;
	return ans;
}

int main()
{
	int N;
	scanf("%d", &N);
	a.resize(N+1);

	for(int i=1; i < N; i++)
	{
		int u, v;
		scanf("%d%d", &u, &v);

		a[u].push_back(v);
		a[v].push_back(u);
	}

	memset(cache, -1, sizeof(cache));

	int ans = 987654321;
	for(int i=1; i <= 9; i++)
		ans = min(ans, solve(1, i));
	printf("%d", ans);
	return 0;
}