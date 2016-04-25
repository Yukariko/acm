#include <bits/stdc++.h>

using namespace std;

char a[101];
char b[101];
int cache[101][101];

int solve(int apos, int bpos)
{
	if(a[apos] == 0 && b[bpos] == 0)
		return true;
	if(b[bpos] == 0)
		return a[apos] == '*' && a[apos + 1] == 0;

	int& ans = cache[apos][bpos];
	if(ans != -1)
		return ans;

	ans = false;
	if(a[apos] == '*')
		ans |= solve(apos, bpos + 1) | solve(apos + 1, bpos);
	else if(a[apos] == b[bpos])
		ans |= solve(apos + 1, bpos + 1);
	return ans;
}

int main()
{
	scanf("%s", a);

	int N;
	scanf("%d", &N);
	for(int i=0; i < N; i++)
	{
		scanf("%s", b);
		memset(cache, -1, sizeof(cache));
		if(solve(0, 0))
			puts(b);
	}

	return 0;
}