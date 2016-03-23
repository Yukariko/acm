#include <bits/stdc++.h>

using namespace std;

const int INF = 987654321;

int N;
vector<int> a[3];

int rcnt(int pos, int pos2, int pos3)
{
	if(pos3 == 2)
		pos = (pos - 1 + N / 3) % N + 1;
	else if(pos3 == 3)
		pos = (pos - 1 + N / 3 * 2) % N + 1;
	return min(abs(pos - pos2), N - abs(pos - pos2));
}

int cache[101][101][101][4];

int solve(int apos, int bpos, int cpos, int order)
{
	if(apos == a[0].size() && bpos == a[1].size() && cpos == a[2].size())
		return 0;

	int& ans = cache[apos][bpos][cpos][order];
	if(ans != -1)
		return ans;

	int pos;
	switch(order)
	{
	case 0: pos = 1; break;
	case 1: pos = a[0][apos-1]; break;
	case 2: pos = (a[1][bpos-1] - 1 - N / 3 + N) % N + 1; break;
	case 3: pos = (a[2][cpos-1] - 1 - N / 3 * 2 + N) % N + 1; break;
	}

	ans = INF;
	if(apos < a[0].size())
		ans = min(ans, rcnt(pos, a[0][apos], 1) + solve(apos+1, bpos, cpos, 1));
	if(bpos < a[1].size())
		ans = min(ans, rcnt(pos, a[1][bpos], 2) + solve(apos, bpos+1, cpos, 2));
	if(cpos < a[2].size())
		ans = min(ans, rcnt(pos, a[2][cpos], 3) + solve(apos, bpos, cpos+1, 3));
	return ans;
}

int main()
{
	memset(cache, -1, sizeof(cache));
	scanf("%d", &N);
	for(int i=0; i < 3; i++)
	{
		int l;
		scanf("%d", &l);
		for(int j=0; j < l; j++)
		{
			int n;
			scanf("%d", &n);
			a[i].push_back(n);
		}
	}

	printf("%d", solve(0, 0, 0, 0));
	return 0;
}