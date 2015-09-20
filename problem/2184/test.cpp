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
int a[1001];
int cache[1001][1001][2];
int s[1001];



int solve(int l, int r, int p)
{
	if(l == 0 && r == N-1)
		return 0;

	int& ret = cache[l][r][p];
	if(ret != -1)
		return ret;

	ret = 987654321;
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
	memset(cache, -1, sizeof(cache));
	cin >> N >> L;

	bool find = false;
	for(int i=0; i < N; i++)
	{
		cin >> a[i];
		if(a[i] == L)
			find = true;
	}

	if(!find)
		a[N++] = L;

	sort(a, a + N);

	int pos = 0;
	for(int i=1; i < N; i++)
	{
		if(a[i] == L)
		{
			pos = i;
			break;
		}
	}

	for(int i=1; i < N; i++)
		s[i] = s[i-1] + a[i] - a[i-1];

	cout << solve(pos, pos, LEFT);

	return 0;
}