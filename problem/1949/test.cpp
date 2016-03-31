#include <bits/stdc++.h>

using namespace std;

const int CHOOSED = 0;
const int YET = 1;
const int MUST = 2;

int N;
int a[10001];
vector<int> adj[10001];

bool visit[10001];
int cache[10001][3];

int solve(int here, int selected)
{
	int& ans = cache[here][selected];
	if(ans != -1)
		return ans;

	visit[here] = true;
	ans = 0;
	if(selected == MUST)
		ans = a[here];

	int ans2 = a[here];
	int ans3 = 0;
	for(size_t i=0; i < adj[here].size(); i++)
	{
		int there = adj[here][i];
		if(visit[there])
			continue;

		if(selected == MUST)
			ans += solve(there, CHOOSED);
		else if(selected == CHOOSED)
			ans += solve(there, YET);
		else
		{
			ans += solve(there, YET);
			ans2 += solve(there, CHOOSED);
		}
	}

	if(selected == YET)
	{
		for(size_t i=0; i < adj[here].size(); i++)
		{
			int there = adj[here][i];
			if(visit[there])
				continue;
			ans = max(ans, ans - solve(there, YET) + solve(there, MUST));
		}
		ans = max(ans, ans2);
	}
	visit[here] = false;
	return ans;
}

int main()
{
	memset(cache, -1, sizeof(cache));
	scanf("%d", &N);
	for(int i=1; i <= N; i++)
		scanf("%d", &a[i]);

	for(int i=1; i < N; i++)
	{
		int u, v;
		scanf("%d%d", &u, &v);
		adj[u].push_back(v);
		adj[v].push_back(u);
	}

	int ans = max({solve(1, YET), solve(1, MUST)});
	printf("%d", ans);
	return 0;
}