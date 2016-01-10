#include <bits/stdc++.h>

using namespace std;

int C,D,d;
vector<int> a, b;
int cache[101][2][102][2];

int berest(bool rest)
{
	return d + (rest? 0: D);
}

int solve(int aPos, bool arest, int bPos, bool brest)
{
	if(aPos == a.size() && bPos == b.size())
		return 0;

	if(aPos == a.size())
		return berest(arest) + C + solve(aPos, true, bPos + 1, false);

	if(bPos == b.size())
		return berest(brest) + C + solve(aPos + 1, false, bPos, true);

	int& ans = cache[aPos][arest][bPos][brest];
	if(ans != -1)
		return ans;

	ans = 987654321;
	ans = min(ans, berest(arest) + C + solve(aPos, true, bPos + 1, false));
	ans = min(ans, berest(brest) + C + solve(aPos + 1, false, bPos, true));
	ans = min(ans, (a[aPos] == b[bPos]? C: 2 * C) + solve(aPos + 1, false, bPos + 1, false));

	return ans;
}

int main()
{
	int T;
	scanf("%d",&T);
	while(T--)
	{
		a.clear();
		b.clear();
		memset(cache, -1, sizeof(cache));
		scanf("%d%d%d",&C,&D,&d);

		int n;
		while(scanf("%d",&n), n)
			a.push_back(n);
		while(scanf("%d",&n), n)
			b.push_back(n);

		printf("%d\n", solve(0, false, 0, false));
	}
	return 0;
}