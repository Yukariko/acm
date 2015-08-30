#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;

long long cache[101][21];

long long solve(int s, int k)
{
	if(k == 0)
		return s == 0;

	long long& ret = cache[s][k];
	if(ret != -1)
		return ret;

	ret = 0;
	for(int i=1; i <= s; i++)
		ret = max(ret, i * solve(s-i,k-1));

	return ret;
}

int main()
{
	memset(cache, -1, sizeof(cache));

	int S, K;
	cin >> S >> K;

	cout << solve(S, K);
}