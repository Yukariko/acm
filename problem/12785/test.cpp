#include <bits/stdc++.h>

using namespace std;

const int MOD = 1000007;

int W, H;
int mx, my;

int cache[201][201][2];

int solve(int y, int x, bool pass)
{
	if(y > H || x > W)
		return 0;
	if(y == H && x == W)
		return pass;

	int& ans = cache[y][x][pass];
	if(ans != -1)
		return ans;

	if(y == my && x == mx)
		pass = true;

	return ans = (solve(y + 1, x, pass) + solve(y, x + 1, pass)) % MOD;
}

int main()
{
	scanf("%d%d%d%d", &W, &H, &mx, &my);
	memset(cache, -1, sizeof(cache));
	printf("%d", solve(1, 1, false));
	return 0;
}