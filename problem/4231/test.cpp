#include <bits/stdc++.h>

using namespace std;

int N;
double a[366];
double cache[366][2];

double solve(int pos, bool can)
{
	if(pos == N)
		return !can? 1000: 0;
	double& ans = cache[pos][can];
	if(ans != -1)
		return ans;

	ans = solve(pos + 1, can);
	if(can)
		ans = max(ans, floor(solve(pos + 1, !can) / a[pos] * 97) / 100);
	else
		ans = max(ans, floor(solve(pos + 1, !can) * a[pos] * 97) / 100);
	return ans;
}

int main()
{
	
	while(scanf("%d", &N), N)
	{
		for(int i=0; i < N; i++)
			scanf("%lf", &a[N-1-i]);

		fill(&cache[0][0], &cache[N][0], -1);
		printf("%.2f\n", max(1000.0, solve(0, false)));
	}
	return 0;
}