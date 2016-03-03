#include <bits/stdc++.h>

using namespace std;

char a[21];

int plen, qlen;
char p[101];
char q[101];

int cache[21][101][2];

int solve(int pos, int pc, bool up)
{

	if(a[pos] == 0)
		return 1;

	int& ans = cache[pos][pc][up];
	if(ans != -1)
		return ans;

	ans = 0;
	if(!up)
	{
		for(int i=pc; i < plen; i++)
			if(p[i] == a[pos])
				ans += solve(pos + 1, i + 1, true);
	}
	else
	{
		for(int i=pc; i < qlen; i++)
			if(q[i] == a[pos])
				ans += solve(pos + 1, i + 1, false);
	}

	return ans;
}

int main()
{
	memset(cache, -1, sizeof(cache));
	gets(a);
	plen = strlen(gets(p));
	qlen = strlen(gets(q));
	printf("%d", solve(0, 0, false) + solve(0, 0, true));
	return 0;
}