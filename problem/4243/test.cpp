#include <iostream>
#include <algorithm>
#include <cstring>
#include <vector>
#include <cstdio>
#include <map>

using namespace std;

#define LEFT 0
#define RIGHT 1

int N, L;
int a[101];
long long cache[101][101][2];
long long s[101];

long long solve(int l, int r, int p)
{
	if(l == 0 && r == N-1)
		return 0;

	long long& ret = cache[l][r][p];
	if(ret != -1)
		return ret;

	ret = 987654321987654LL;
	int cnt = N - (r - l + 1);

	if(l > 0)
	{
		if(p == LEFT)
			ret = min(ret, (s[l] - s[l-1]) * cnt + solve(l-1, r, LEFT));
		else
			ret = min(ret, (s[r] - s[l-1]) * cnt + solve(l-1, r, LEFT));
	}

	if(r < N-1)
	{
		if(p == LEFT)
			ret = min(ret, (s[r+1] - s[l]) * cnt + solve(l, r+1, RIGHT));
		else
			ret = min(ret, (s[r+1] - s[r]) * cnt + solve(l, r+1, RIGHT));
	}
	return ret;
}

int main()
{
	int T;
	cin >> T;

	while(T--)
	{
		memset(cache, -1, sizeof(cache));
		cin >> N >> L;

		L--;
		for(int i=0; i < N-1; i++)
			cin >> a[i];

		s[0] = 0;
		for(int i=1; i < N; i++)
			s[i] = s[i-1] + a[i-1];

		cout << solve(L, L, LEFT) << '\n';
	}


	return 0;
}