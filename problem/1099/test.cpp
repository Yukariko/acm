// dynamic
#include <bits/stdc++.h>

using namespace std;

const int INF = 987654321;

char a[51];
int N, L;

char b[51][51];
int len[51];
int check[51][26];

int cache[51];

int score(int pos, int sel)
{
	int ans = 0;
	for(int i=0; i < len[sel]; i++)
		if(b[sel][i] != a[i+pos])
			ans++;
	return ans;
}

int solve(int pos)
{
	if(pos == L)
		return 0;

	int& ans = cache[pos];
	if(ans != -1)
		return ans;

	ans = INF;

	int ck[26] = {};

	for(int i=pos; a[i]; i++)
	{
		ck[a[i]-'a']++;
		for(int j=0; j < N; j++)
		{
			if(i - pos + 1 != len[j])
				continue;
			bool find = true;
			for(int k=0; k < 26; k++)
				if(check[j][k] != ck[k])
				{
					find = false;
					break;
				}
			if(find)
				ans = min(ans, score(pos, j) + solve(i+1));
		}
	}
	return ans;
}

int main()
{
	memset(cache, -1, sizeof(cache));
	L = strlen(gets(a));
	scanf("%d", &N);
	for(int i=0; i < N; i++)
	{
		scanf("%s", b[i]);
		for(int j=0; b[i][j]; j++)
			check[i][b[i][j]-'a']++;
		len[i] = strlen(b[i]);
	}

	int ans = solve(0);
	printf("%d", ans == INF? -1: ans);
	return 0;
}