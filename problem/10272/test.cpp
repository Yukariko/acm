#include <bits/stdc++.h>

using namespace std;

int N;
pair<int, int> a[512];

double sq(double n)
{
	return n * n;
}
double dist(int p, int q)
{
	return sqrt(sq(a[p].first - a[q].first) + sq(a[p].second - a[q].second));
}

double cache[513][513];
double solve(int pos, int apos, int bpos)
{
	if(pos == N)
		return dist(apos, bpos);

	double& ans = cache[apos][bpos];
	if(ans != -1.0)
		return ans;

	ans = dist(apos, pos) + solve(pos + 1, pos, bpos);
	ans = min(ans, dist(bpos, pos) + solve(pos + 1, apos, pos));
	return ans;
}

int main()
{
	int T;
	scanf("%d",  &T);

	while(T--)
	{
		scanf("%d", &N);
		for(int i=0; i < N; i++)
			scanf("%d%d", &a[i].first, &a[i].second);
		fill(&cache[0][0], &cache[N][0], -1.0);

		sort(a, a + N);
		printf("%f\n", solve(1, 0, 0));
	}
	return 0;
}