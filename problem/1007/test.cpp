#include <iostream>
#include <algorithm>
#include <cstring>
#include <vector>
#include <cstdio>
#include <cmath>
#include <map>

using namespace std;

int N;
int a[21][2];

double cache[20][1<<19];

double solve(int pos, int visit)
{
	if(pos == N)
	{
		long long p=0, q=0;
		int plus=0, minus=0;
		for(int i=0; i < N; i++)
		{
			if(visit & (1 << i))
			{
				p += a[i][0];
				q += a[i][1];
				plus++;
			}
			else
			{
				p -= a[i][0];
				q -= a[i][1];
				minus++;
			}
		}
		if(plus != minus)
			return 987654321.0;
		return sqrt(p*p + q*q);
	}
	double& ret = cache[pos][visit];
	if(ret != -1)
		return ret;

	return ret = min(solve(pos+1, visit << 1), solve(pos+1, (visit << 1) | 1));
}

int main()
{
	int T;
	cin >> T;

	cout.setf(ios::fixed);
	cout.precision(6);
	while(T--)
	{
		cin >> N;
		for(int i=0; i < N; i++)
			for(int j=0; j < (1<<(N-1)); j++)
				cache[i][j] = -1;

		for(int i=0; i < N; i++)
			cin >> a[i][0] >> a[i][1];

		cout << solve(0,0) << '\n';
	}

	return 0;
}