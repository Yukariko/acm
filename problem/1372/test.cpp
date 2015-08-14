#include <iostream>
#include <algorithm>
#include <cstring>
#include <vector>

using namespace std;

const int MAX_N = 12;

vector<string> a;
int dp[MAX_N+1][MAX_N+1];
int N;

bool pass(string &p, string &q, int pos)
{
	for(int i=0; p[i+pos] && q[i]; i++)
		if(p[i+pos] != q[i])
			return false;
	return true;
}

int cache[MAX_N+1][1<<MAX_N];

int solve(int last, int used)
{
	if(used == (1 << N) - 1)
		return 0;

	int& ret = cache[last][used];
	if(ret != -1)
		return ret;

	ret = 0;
	for(int next = 0; next < N; next++)
	{
		if((used & (1 << next)) == 0)
		{
			int cand = dp[last][next] + solve(next, used | (1 << next));
			ret = max(ret, cand);
		}
	}

	return ret;
}

string construct(int last, int used)
{
	if(used == (1 << N) - 1)
		return "";
	
	string ans="|";

	int selNext;
	for(int next = 0; next < N; next++)
	{
		if(used & (1<<next))
			continue;

		int ifUsed = dp[last][next] + solve(next, used | (1<<next));
		string part = a[next].substr(dp[last][next]);
		if(solve(last,used) == ifUsed && part < ans)
		{
			ans = part;
			selNext = next;
		}
	}
	return a[selNext].substr(dp[last][selNext]) + construct(selNext, used | (1 << selNext));
}

int main()
{
	memset(cache, -1, sizeof(cache));
	cin >> N;

	string b[MAX_N];
	for(int i=0; i < N; i++)
		cin >> b[i];

	for(int i=0; i < N; i++)
	{
		bool overlap = false;
		for(int j=0; j < N; j++)
		{
			if(i != j && b[j].find(b[i]) != -1)
			{
				overlap = true;
				b[i][0] = 0;
				break;
			}
		}
		if(overlap == false)
			a.push_back(b[i]);
	}

	N = a.size();
	for(int i=0; i < N; i++)
	{
		for(int j=0; j < N; j++)
		{
			if(i==j)
				continue;
			for(int k=0; a[i][k]; k++)
			{
				if(pass(a[i], a[j], k))
				{
					dp[i][j] = a[i].length() - k;
					break;
				}
			}
		}
	}
	
	solve(MAX_N, 0);
	cout << construct(MAX_N, 0);
	return 0;
}