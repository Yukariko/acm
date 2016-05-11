#include <bits/stdc++.h>

using namespace std;

char a[101];

long long cache[101][3][3][2];

bool isvowel(char c)
{
	return c == 'A' || c == 'E' || c == 'I' || c == 'O' || c == 'U';
}

long long solve(int pos, int v, int nv, bool l)
{
	if(v >= 3 || nv >= 3)
		return 0;
	if(a[pos] == 0)
		return l;

	long long& ans = cache[pos][v][nv][l];
	if(ans != -1)
		return ans;

	if(a[pos] != '_')
	{
		if(isvowel(a[pos]))
			ans = solve(pos + 1, v + 1, 0, l);
		else
			ans = solve(pos + 1, 0, nv + 1, l || a[pos] == 'L');
	}
	else
	{
		ans = 0;
		for(char c='A'; c <= 'Z'; c++)
			if(isvowel(c))
				ans += solve(pos + 1, v + 1, 0, l);
			else
				ans += solve(pos + 1, 0, nv + 1, l || c == 'L');
	}	

	return ans;
}

int main()
{
	scanf("%s", a);
	memset(cache, -1, sizeof(cache));
	printf("%lld", solve(0, 0, 0, false));
	return 0;
}