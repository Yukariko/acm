#include <bits/stdc++.h>

using namespace std;

const int INF = 987654321;

int N, M, K;
vector<pair<int,int>> V[301];
int cache[301][301];

int solve(int pos, int cnt)
{
	if(cnt < 0)
		return -INF;
	if(pos == N)
		return 0;

	int& ans = cache[pos][cnt];
	if(ans != -1)
		return ans;

	if(V[pos].empty())
		return ans = -INF;

	ans = -INF;
	for(size_t i=0; i < V[pos].size(); i++)
		ans = max(ans, V[pos][i].second + solve(V[pos][i].first, cnt-1));
	return ans;
}

int main()
{
	memset(cache, -1, sizeof(cache));
	scanf("%d%d%d", &N, &M, &K);
	for(int i=0; i < K; i++)
	{
		int u, v, w;
		scanf("%d%d%d", &u, &v, &w);

		if(u < v)
			V[u].push_back({v, w});
	}

	printf("%d", solve(1, M-1));
	return 0;
}