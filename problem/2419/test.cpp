#include <bits/stdc++.h>

using namespace std;

const int INF = 987654321;

int N, M;
int a[302];
int s[302];

int cache[302][302][2];

int solve(int left, int right, bool lr, int eat)
{
	if(eat == 0)
		return 0;
	if(left == 0 && right == N-1)
		return 0;

	int& ans = cache[left][right][lr];
	if(ans != -INF)
		return ans;

	ans = -INF + 1;

	if(left > 0)
	{
		int earnCandy;		
		if(lr == false)
			earnCandy = M + -(s[left] - s[left-1]) * eat;
		else
			earnCandy = M + -(s[right] - s[left-1]) * eat;
		ans = max(ans, earnCandy + solve(left-1, right, false, eat-1));
	}

	if(right < N-1)
	{
		int earnCandy;
		if(lr == false)
			earnCandy = M + -(s[right+1] - s[left]) * eat;
		else
			earnCandy = M + -(s[right+1] - s[right]) * eat;
		ans = max(ans, earnCandy + solve(left, right+1, true, eat-1));
	}
	return ans;
}

int main()
{
	scanf("%d%d", &N, &M);

	bool findZero = false;
	for(int i=0; i < N; i++)
	{
		scanf("%d", &a[i]);
		if(a[i] == 0)
			findZero = true;
	}

	if(findZero == false)
		a[N++] = 0;

	sort(a, a + N);

	for(int i=1; i < N; i++)
		s[i] = s[i-1] + a[i] - a[i-1];

	int zeroPos = lower_bound(a, a + N, 0) - a;

	int ans = 0;
	for(int i=1; i <= N; i++)
	{
		fill(&cache[0][0][0], &cache[302][0][0], -INF);
		ans = max(ans, (findZero? M : 0) + solve(zeroPos, zeroPos, false, i-1));
	}

	printf("%d", ans);
	return 0;
}