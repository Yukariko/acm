#include <bits/stdc++.h>

using namespace std;

const long long INF = 98765432111111LL;

const int NOTJOIN = 0;
const int JOIN = 1;
const int SIDE = 2;

int N;
vector<pair<int, int>> adj[10001];
long long cache[10001][3];
bool visit[10001];

long long solve(int here, int join)
{
	long long& ans = cache[here][join];
	if(ans != -1)
		return ans;

	visit[here] = true;

	ans = 0;

	priority_queue<long long> pq;

	for(size_t i=0; i < adj[here].size(); i++)
	{
		int there = adj[here][i].first;
		int cost = adj[here][i].second;

		if(visit[there])
			continue;

		long long single = cost + solve(there, SIDE);
		if(join == SIDE)
			ans = max(ans, single);
		else if(join == NOTJOIN)
			ans = max({ans, solve(there, NOTJOIN), solve(there, JOIN), solve(there, SIDE)});
		else
		{
		
			pq.push(-single);
			while(pq.size() > 2)
				pq.pop();
		}
	}

	visit[here] = false;
	if(join != JOIN)
		return ans;

	if(pq.size() < 2)
		return ans = -INF;

	long long ret = -pq.top();
	pq.pop();
	ret += -pq.top();

	ans = max(ans, ret);
	return ans;
}

int main()
{
	N = 10000;
	int u, v, w;
	int m = 0;
	while(~scanf("%d%d%d", &u, &v, &w))
	{
		adj[u].push_back({v, w});
		adj[v].push_back({u, w});
		m = max(m, w);
	}

	memset(cache, -1, sizeof(cache));
	for(int i=1; i <= N; i++)
		if(adj[i].size() > 1)
			return printf("%lld", max({solve(i, NOTJOIN), solve(i, JOIN), solve(i, SIDE)})), 0;
	printf("%d", m);
	return 0;
}