#include <iostream>
#include <algorithm>
#include <cstring>
#include <vector>
#include <cstdio>
#include <map>

using namespace std;

int cache[1001];

int solve(int n)
{
	if(n == 1)
		return 1;

	int& ans = cache[n];
	if(ans)
		return ans;

	ans = 1;
	for(int i=1; i * 2 <= n; i++)
		ans += solve(i);
	return ans;
}

int main()
{
	int T;
	cin >> T;

	while(T--)
	{
		int N;
		cin >> N;

		cout << solve(N) << '\n';
	}

	return 0;
}