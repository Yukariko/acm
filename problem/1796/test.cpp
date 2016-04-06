#include <bits/stdc++.h>

using namespace std;

const int INF = 30000;

char a[1001];
vector<int> b[26];

int len;
short cache[26][1001][1001][2];

short solve(int pos, int left, int right, bool force)
{
	if(pos == 26)
		return 0;

	short& ans = cache[pos][left][right][force];
	if(ans != -1)
		return ans;

	if(b[pos].empty())
		return ans = solve(pos + 1, left, right, force);

	if(left <= b[pos][0] && b[pos].back() <= right)
		return ans = solve(pos + 1, force? right: left, force? right: left, true);

	ans = INF;
	if(left > b[pos][0])
		ans = min<short>(ans, (force? right - left + 1: 1) + solve(pos, left-1, right, false));
	if(right < b[pos].back())
		ans = min<short>(ans, (force? 1: right + 1 - left ) + solve(pos, left, right+1, true));
	return ans;
}

int main()
{
	memset(cache, -1, sizeof(cache));
	scanf("%s", a);
	len = strlen(a);
	for(int i=0; a[i]; i++)
		b[a[i] - 'a'].push_back(i);
	
	printf("%d", solve(0, 0, 0, true) + len);
	return 0;
}