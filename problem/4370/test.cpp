#include <bits/stdc++.h>

using namespace std;

map<pair<long long, bool>, bool> cache;
long long N;

bool solve(long long n, bool turn)
{
	if(n >= N)
		return !turn;

	if(cache.find(make_pair(n, turn)) != cache.end())
		return cache[make_pair(n, turn)];

	bool& ret = cache[make_pair(n, turn)];

	for(int i=2; i <= 9; i++)
		if(solve(n * i, !turn) == turn)
			return ret = turn;
	return ret = !turn;
}

int main()
{
	const char *res[] = {"Baekjoon", "Donghyuk"};
	while(~scanf("%lld",&N))
	{
		cache.clear();
		printf("%s wins.\n", res[solve(1, 0)]);
	}
	return 0;
}