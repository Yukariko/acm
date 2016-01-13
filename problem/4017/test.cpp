#include <bits/stdc++.h>

using namespace std;

int N, C;
vector<int> start;
vector<int> favor, hate;

int firstMask;

int cache[50001][1<<5];

int getPosition(int s, int p)
{
	if(p < s)
		p += N;
	return p - s;
}

bool isFavor(int mask, int emotion)
{
	return (mask & emotion) != 0;
}

bool isValid(int pos, int mask, int nextMask)
{
	int firstDiff = getPosition(start[pos+1], start[0]);
	if(firstDiff < 5)
	{
		int check = nextMask >> firstDiff;
		if(check != (firstMask & ((1 << (5-firstDiff)) - 1)))
			return false;
	}
	return true;
}

int solve(int pos, int mask)
{
	int& ans = cache[pos][mask];
	if(ans != -1)
		return ans;
	
	int pick = 0;
	if(isFavor(mask, favor[pos]))
		pick = 1;
	else if(isFavor(~mask, hate[pos]))
		pick = 1;

	ans = pick;
	if(pos == C-1)
		return ans;

	int diff = getPosition(start[pos], start[pos + 1]);
	if(diff == 0)
		return ans = max(ans, pick + solve(pos+1, mask));

	int end = diff < 5? 1 << diff: 32;
	for(int i=0; i < end; i++)
	{
		int nextMask = diff < 5 ? (i << (5 - diff)) | (mask >> diff) : i;
		if(isValid(pos, mask, nextMask))
			ans = max(ans, pick + solve(pos+1, nextMask));
	}
	return ans;
}


int main()
{
	scanf("%d%d",&N,&C);

	start.resize(C);
	favor.resize(C);
	hate.resize(C);

	for(int i=0; i < C; i++)
	{
		int E, F, L;
		scanf("%d%d%d",&E,&F,&L);

		E--;
		start[i] = E;

		hate[i] = 0;
		for(int j=0; j < F; j++)
		{
			int n;
			scanf("%d",&n);
			n--;
			if(n < E)
				n += N;
			hate[i] |= 1 << (n - E);
		}

		favor[i] = 0;
		for(int j=0; j < L; j++)
		{
			int n;
			scanf("%d",&n);
			n--;
			if(n < E)
				n += N;
			favor[i] |= 1 << (n - E);
		}
	}

	int ans = 0;
	while(firstMask < 32)
	{
		memset(cache, -1, sizeof(cache));
		ans = max(ans, solve(0, firstMask));
		firstMask++;
	}

	printf("%d", ans);
	return 0;
}