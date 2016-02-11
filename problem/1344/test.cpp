#include <bits/stdc++.h>

using namespace std;

int a, b;
double cache[19][19][19];

bool is_prime(int N)
{
	if(N <= 1)
		return false;

	for(int i=2; i * i <= N; i++)
		if(N % i == 0)
			return false;
	return true;
}

double solve(int pos, int p, int q)
{
	if(pos == 18)
	{
		return is_prime(p) || is_prime(q)? 1.0: 0.0;
	}

	double& ans = cache[pos][p][q];
	if(ans >= 0.0)
		return ans;

	ans = 0;
	ans += (a / 100.0) * (b / 100.0) * solve(pos + 1, p + 1, q + 1);
	ans += (a / 100.0) * ((100 - b) / 100.0) * solve(pos + 1, p + 1, q);
	ans += ((100 - a) / 100.0) * (b / 100.0) * solve(pos + 1, p, q + 1);
	ans += ((100 - a) / 100.0) * ((100 - b) / 100.0) * solve(pos + 1, p, q);
	return ans;
}

int main()
{
	fill(&cache[0][0][0], &cache[19][0][0], -1.0);
	scanf("%d%d", &a, &b);
	printf("%.8f", solve(0, 0, 0));
	return 0;
}