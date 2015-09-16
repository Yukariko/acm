#include <iostream>
#include <algorithm>
#include <cstring>
#include <vector>
#include <cstdio>
#include <map>

using namespace std;

int TN, N, K;

long long cache[18][1<<17];

long long solve(int pos, int visit)
{
	if(pos == N)
		return 1;

	long long& ret = cache[pos][visit];
	if(ret)
		return ret;

	for(int i=0; i < N; i++)
	{
		if(pos < K && pos == i)
			continue;
		if((visit & (1 << i)) == 0)
			ret += solve(pos+1, visit | (1 << i));
	}
	return ret;
}

int main()
{
	int T;
	cin >> T;

	while(T--)
	{
		cin >> TN >> N >> K;
		memset(cache, 0, sizeof(cache));
		cout << TN << " " << solve(0,0) << '\n';
	}
	return 0;
}