#include <iostream>
#include <algorithm>
#include <cstring>
#include <vector>
#include <cstdio>
#include <map>

using namespace std;

string a, b;
int dp[5001][5001];
int as[26], ae[26];
int bs[26], be[26];

int solve(int pos, int aPos, int bPos)
{
	if(a[aPos] == 0 && b[bPos] == 0)
		return 0;

	int& ret = dp[aPos][bPos];
	if(ret != -1)
		return ret;

	int aPick = a[aPos] - 'A';
	int bPick = b[bPos] - 'A';

	ret = 987654321;

	if(a[aPos])
	{
		if(as[aPick] == aPos && (bs[aPick] == -1 || bs[aPick] >= bPos))
		{
			if(ae[aPick] == aPos && bs[aPick] == -1)
				ret = min(ret, solve(pos+1, aPos+1, bPos));
			else
				ret = min(ret, -pos + solve(pos+1, aPos+1, bPos));			
		}
		else if(ae[aPick] == aPos && (be[aPick] == -1 || be[aPick] < bPos))
		{
			if(as[aPick] == aPos && be[aPick] == -1)
				ret = min(ret, solve(pos+1, aPos+1, bPos));
			else
				ret = min(ret, pos + solve(pos+1, aPos+1, bPos));
		}
		else
			ret = min(ret, solve(pos+1, aPos+1, bPos));
	}

	if(b[bPos])
	{
		if(bs[bPick] == bPos && (as[bPick] == -1 || as[bPick] >= aPos))
		{
			if(be[bPick] == bPos && as[bPick] == -1)
				ret = min(ret, solve(pos+1, aPos, bPos+1));
			else
				ret = min(ret, -pos + solve(pos+1, aPos, bPos+1));
		}
		else if(be[bPick] == bPos && (ae[bPick] == -1 || ae[bPick] < aPos))
		{
			if(bs[bPick] == bPos && ae[bPick] == -1)
				ret = min(ret, solve(pos+1, aPos, bPos+1));
			else
				ret = min(ret, pos + solve(pos+1, aPos, bPos+1));
		}
		else
			ret = min(ret, solve(pos+1, aPos, bPos+1));
	}
	return ret;
}

int main()
{
	int T;
	cin >> T;

	while(T--)
	{
		cin >> a >> b;

		memset(as, -1, sizeof(as));
		memset(ae, -1, sizeof(ae));
		memset(bs, -1, sizeof(bs));
		memset(be, -1, sizeof(be));

		for(int i=0; a[i]; i++)
		{
			if(as[a[i]-'A'] == -1)
				as[a[i]-'A'] = i;
			ae[a[i]-'A'] = i;
		}

		for(int i=0; b[i]; i++)
		{
			if(bs[b[i]-'A'] == -1)
				bs[b[i]-'A'] = i;
			be[b[i]-'A'] = i;
		}

		memset(dp, -1, sizeof(dp));
		cout << solve(0, 0, 0) << '\n';
	}
	return 0;
}