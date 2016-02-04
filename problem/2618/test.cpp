#include <bits/stdc++.h>

using namespace std;

int N;
int W;
int a[1003][2];
int cache[1003][1003];

int dist(int p, int q)
{
	return abs(a[p][0] - a[q][0]) + abs(a[p][1] - a[q][1]);
}

int solve(int apos, int bpos)
{
	int next = 1 + max(apos, bpos);
	if(next == W)
		return 0;

	int& ans = cache[apos][bpos];
	if(ans != -1)
		return ans;

	int distA = dist(apos, next);
	int distB = dist(bpos, next);
	ans = min(distA + solve(next, bpos), distB + solve(apos, next));
	return ans;
}

void construct(int apos, int bpos)
{
	int next = 1 + max(apos, bpos);
	if(next == W)
		return;

	int distA = dist(apos, next);
	int distB = dist(bpos, next);
	if(distA + solve(next, bpos) < distB + solve(apos, next))
	{
		puts("1");
		construct(next, bpos);
	}
	else
	{
		puts("2");
		construct(apos, next);
	}
}

int main()
{
	memset(cache, -1, sizeof(cache));
	scanf("%d%d", &N, &W);
	W+=2;
	a[0][0] = 1;
	a[0][1] = 1;
	a[1][0] = N;
	a[1][1] = N;
	for(int i=2; i < W; i++)
		scanf("%d%d", &a[i][0], &a[i][1]);

	printf("%d\n", solve(0, 1));
	construct(0, 1);
	return 0;
}