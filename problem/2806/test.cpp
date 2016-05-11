#include <bits/stdc++.h>

using namespace std;

const int INF = 987654321;

int N;
char a[1000001];

int cache[1000001][2];

int solve(int pos, char ch)
{
	if(pos == N)
		return ch == 'B';

	int& ans = cache[pos][ch-'A'];
	if(ans != -1)
		return ans;

	ans = INF;
	if(ch != a[pos])
	{
		ans = min(ans, 1 + solve(pos + 1, ch));
		ans = min(ans, 2 + solve(pos + 1, ch == 'A'? 'B': 'A'));
	}
	else
	{
		ans = min(ans, solve(pos + 1, ch));
		ans = min(ans, 1 + solve(pos + 1, ch == 'A'? 'B': 'A'));
	}
	return ans;
}

int main()
{
	scanf("%d", &N);
	scanf("%s", a);
	memset(cache, -1, sizeof(cache));
	printf("%d", min(solve(0, 'A'), solve(0, 'B')));
	return 0;
}