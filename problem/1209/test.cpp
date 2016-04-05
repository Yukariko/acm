#include <bits/stdc++.h>

using namespace std;

int N;
int a[2001];
int b[2001];

long long cache[2001][2001][2];

long long solve(int pos, int bpos, bool asc)
{
	if(pos == N)
		return 0;

	long long& ans = cache[pos][bpos][asc];
	if(ans != -1)
		return ans;

	int add = asc? 1: -1;
	ans = llabs(b[bpos] - a[pos]) + solve(pos + 1, bpos, asc);
	if(bpos + add >= 0 && bpos + add < N)
		ans = min(ans, solve(pos, bpos + add, asc));
	return ans;
}

int main()
{
	memset(cache, -1, sizeof(cache));
	scanf("%d", &N);
	for(int i=0; i < N; i++)
	{
		scanf("%d", &a[i]);
		b[i] = a[i];
	}

	sort(b, b + N);

	printf("%lld", min(solve(0, 0, true), solve(0, N-1, false)));
	return 0;
}