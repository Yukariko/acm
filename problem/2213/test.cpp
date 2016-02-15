#include <bits/stdc++.h>

using namespace std;

int N;
int a[10001];

vector<int> adj[10001];
vector<int> tree[10001];
bool visit[10001];

int cache[10001][2];

void makeTree(int here)
{
	for(size_t i=0; i < adj[here].size(); i++)
	{
		int there = adj[here][i];
		if(visit[there])
			continue;
		tree[here].push_back(there);
		visit[there] = true;
		makeTree(there);
		visit[there] = false;
	}
}

int solve(int here, bool pick)
{
	int& ans = cache[here][pick];
	if(ans != -1)
		return ans;

	ans = 0;
	int p = 0, np = a[here];
	for(size_t i=0; i < tree[here].size(); i++)
	{
		int there = tree[here][i];
		p += solve(there, false);
		if(!pick)
			np += solve(there, true);
	}
	if(pick)
		return ans = p;
	return ans = max(p, np);
}

vector<int> ret;

void construct(int here, bool pick)
{
	int p = 0, np = a[here];
	for(size_t i=0; i < tree[here].size(); i++)
	{
		int there = tree[here][i];
		p += cache[there][false];
		if(!pick)
			np += cache[there][true];
	}

	int ans = 0;
	if(pick)
		ans = p;
	else
		ans = max(p, np);

	if(ans == np)
		ret.push_back(here);

	for(size_t i=0; i < tree[here].size(); i++)
	{
		int there = tree[here][i];
		if(ans == np)
			construct(there, true);
		else
			construct(there, false);
	}
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

	visit[1] = true;
	makeTree(1);

	printf("%d\n", solve(1, false));

	construct(1, false);

	sort(ret.begin(), ret.end());
	for(size_t i=0; i < ret.size(); i++)
		printf("%d ", ret[i]);

	return 0;
}