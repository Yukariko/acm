#include <bits/stdc++.h>

using namespace std;

int A, B, C;
char a[3001];
char b[3001];

int cache[3001][3001];

int solve(int apos, int bpos)
{
	if(a[apos] == 0 && b[bpos] == 0)
		return 0;

	int& ans = cache[apos][bpos];
	if(ans != -1)
		return ans;

	if(a[apos] == 0)
		return ans = B + solve(apos, bpos+1);

	if(b[bpos] == 0)
		return ans = B + solve(apos+1, bpos);

	if(a[apos] == b[bpos])
		ans = A + solve(apos+1, bpos+1);
	else
		ans = C + solve(apos+1, bpos+1);
	ans = max(ans, B + solve(apos+1, bpos));
	ans = max(ans, B + solve(apos, bpos+1));
	return ans;
}

int main()
{
	scanf("%d%d%d", &A, &B, &C);
	scanf("%s%s", a, b);

	memset(cache, -1, sizeof(cache));
	printf("%d", solve(0, 0));
	return 0;
}