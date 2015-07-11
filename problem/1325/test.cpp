#include <iostream>
#include <algorithm>
#include <vector>
#include <cstring>

using namespace std;

int N,M;
vector<int> a[10001];
bool visit[10001];

int solve(int pos)
{
	int ret = 0;
	for(vector<int>::iterator it = a[pos].begin(); it != a[pos].end(); ++it)
	{
		if(visit[*it] == false)
		{
			visit[*it] = true;
			ret += 1 + solve(*it);
		}
	}
	return ret;
}


int main()
{
	cin >> N >> M;
	for(int i=0; i < M; i++)
	{
		int p,q;
		cin >> p >> q;
		a[q].push_back(p);
	}

	int ret = 0;
	int dp[10001];
	
	for(int i=1; i <= N; i++)
	{
		memset(visit,0,sizeof(visit));
		visit[i] = true;
		dp[i] = solve(i);
		ret = max(ret, dp[i]);
	}

	for(int i=1; i <= N; i++)
		if(ret == dp[i])
			cout << i << " ";

	return 0;
}