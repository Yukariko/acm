#include <bits/stdc++.h>

using namespace std;

const long long INF = 98765432111111LL;

const int NOTJOIN = 0;
const int JOIN = 1;
const int SIDE = 2;

int N;
vector<pair<int, int>> adj[100001];
long long cache[100001][3];
bool visit[100001];

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
	scanf("%d", &N);
	for(int i=1; i <= N; i++)
	{
		int u, v;
		scanf("%d", &u);
		while(scanf("%d", &v), v != -1)
		{
			int w;
			scanf("%d", &w);

			adj[u].push_back({v, w});
		}
	}

	if(N == 2)
	{
		printf("%d", adj[1][0].second);
		return 0;
	}

	memset(cache, -1, sizeof(cache));
	for(int i=1; i <= N; i++)
		if(adj[i].size() > 1)
			return printf("%lld", max({solve(i, NOTJOIN), solve(i, JOIN), solve(i, SIDE)})), 0;
	return 0;
}