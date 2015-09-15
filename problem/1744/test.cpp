#include <iostream>
#include <algorithm>
#include <cstring>
#include <vector>
#include <cstdio>
#include <map>

using namespace std;

int cache[10001];
int N;
int a[10001];

int solve(int pos)
{
	if(pos == N)
		return 0;

	int& ret = cache[pos];
	if(ret != -1)
		return ret;

	ret = a[pos] + solve(pos+1);
	if(pos + 1 != N)
		ret = max(ret, a[pos] * a[pos+1] + solve(pos+2));
	return ret;
}

int main()
{
	cin >> N;
	for(int i=0; i < N; i++)
		cin >> a[i];

	sort(a, a+N);

	memset(cache, -1, sizeof(cache));
	cout << solve(0);
	return 0;
}