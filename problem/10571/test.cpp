#include <bits/stdc++.h>

using namespace std;

int N;
int cache[201][201];
pair<double, double> a[201];


int solve(int pos, int back)
{
	if(pos == N+1)
		return 0;

	int& ans = cache[pos][back];
	if(ans != -1)
		return ans;

	ans = solve(pos + 1, back);
	if(a[pos].first < a[back].first && a[pos].second > a[back].second)
		ans = max(ans, 1 + solve(pos + 1, pos));

	return ans;
}

int main()
{
	int T;
	scanf("%d", &T);

	a[0] = {100, -1};
	while(T--)
	{
		scanf("%d", &N);

		for(int i=1; i <= N; i++)
			scanf("%lf%lf", &a[i].second, &a[i].first);

		memset(cache, -1, sizeof(cache));
		printf("%d\n", solve(1, 0));
	}
	return 0;
}