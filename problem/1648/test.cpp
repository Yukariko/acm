#include <bits/stdc++.h>

using namespace std;

int getBit(int mask, int N)
{
	return ((mask) & (1 << (N))) >> N;
} 
int setBit(int mask, int N)
{
	return ((mask) | (1 << (N)));
}

set<int> checkMask[1<<14];
vector<int> validMask[1<<14];

int N, M;
int cache[15][1<<14];

void setValidMask(int pos, int before, int after)
{
	if(pos == M)
	{
		if(checkMask[before].find(after) == checkMask[before].end())
		{
			checkMask[before].insert(after);	
			validMask[before].push_back(after);
		}
		return;
	}

	if(getBit(before, pos) == 0)
		setValidMask(pos + 1, before, setBit(after, pos));
	else
		setValidMask(pos + 1, before, after);
	if(pos < M-1 && getBit(before, pos) == getBit(before, pos + 1))
		setValidMask(pos + 2, before, setBit(setBit(after, pos), pos+1));
}

int solve(int pos, int mask)
{
	if(pos == -1)
		return mask == (1 << M) - 1;

	int& ans = cache[pos][mask];
	if(ans != -1)
		return ans;

	ans = 0;
	for(int nextMask=0; nextMask < validMask[mask].size(); nextMask++)
		ans = (ans + solve(pos - 1, validMask[mask][nextMask])) % 9901;

	return ans;
}

int main()
{
	scanf("%d%d", &M, &N);
	for(int mask=0; mask < (1<<M); mask++)
		setValidMask(0, mask, 0);
	memset(cache, -1, sizeof(cache));

	printf("%d", solve(N, 0));
	return 0;
}