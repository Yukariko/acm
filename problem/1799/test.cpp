#include <bits/stdc++.h>

using namespace std;

#define GET(a, x) (a & (1 << (x)))
#define SET(a, x) (a | (1 << (x)))

int N;
vector<int> a[21];

char cache[20][1<<20];

char solve(int pos, int b)
{
	if(pos == N * 2)
		return 0;

	char& ans = cache[pos][b];
	if(ans != -1)
		return ans;

	ans = solve(pos+1, b);
	for(auto &x : a[pos])
	{
		int y = pos - x;
		if(!GET(b, N+y-x-1))
			ans = max<char>(ans, 1 + solve(pos+1, SET(b, N+y-x-1)));
	}
	return ans;
}

int main()
{
	memset(cache, -1, sizeof(cache));
	scanf("%d",&N);
	for(int i=0; i < N; i++)
	{
		for(int j=0; j < N; j++)
		{
			int n;
			scanf("%d",&n);
			if(n == 1)
				a[i+j].push_back(j);
		}
	}

	printf("%d",solve(0, 0));
	return 0;
}