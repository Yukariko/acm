#include <bits/stdc++.h>

using namespace std;

vector<int> getPartialMatch(const string& N)
{
	int m = N.size();
	vector<int> pi(m, 0);

	int begin = 1, matched = 0;
	while(begin + matched < m)
	{
		if(N[begin + matched] == N[matched])
		{
			++matched;
			pi[begin+matched-1] = matched;
		}
		else
		{
			if(matched == 0)
				++begin;
			else
			{
				begin += matched - pi[matched - 1];
				matched = pi[matched - 1];
			}
		}
	}
	return pi;
}

vector<int> kmpSearch(const string& H, const string& N)
{
	int n = H.size(), m = N.size();
	vector<int> ret;
	vector<int> pi = getPartialMatch(N);

	int matched = 0;
	for(int i=0; i < n; i++)
	{
		while(matched > 0 && H[i] != N[matched])
			matched = pi[matched - 1];

		if(H[i] == N[matched])
		{
			++matched;
			if(matched == m)
			{
				ret.push_back(i - m + 1);
				matched = pi[matched - 1];
			}
		}
	}
	return ret;
}

int N, len;
char a[100001];
int b[501];
vector<short> c[100001];
int cache[100001];

int solve(int pos)
{
	if(!a[pos])
		return 0;

	int& ans = cache[pos];
	if(ans != -1)
		return ans;

	ans = solve(pos + 1);
	for(size_t i=0; i < c[pos].size(); i++)
		ans = max(ans, b[c[pos][i]] + solve(pos + b[c[pos][i]]));
	return ans;
}

int main()
{
	scanf("%s", a);
	len = strlen(a);
	scanf("%d", &N);
	for(int i=0; i < N; i++)
	{
		char s[10001];
		scanf("%s", s);

		b[i] = strlen(s);
		vector<int> match = kmpSearch(a, s);
		for(size_t j=0; j < match.size(); j++)
			c[match[j]].push_back(i);
	}

	memset(cache, -1, sizeof(cache));
	printf("%d", solve(0));
	return 0;
}