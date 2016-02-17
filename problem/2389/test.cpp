#include <bits/stdc++.h>

using namespace std;

double sq(double n)
{
	return n * n;
}

int main()
{
	int N;
	scanf("%d", &N);

	vector<pair<double, double>> a(N);

	double ry=0, rx=0;
	for(int i=0; i < N; i++)
	{
		scanf("%lf%lf", &a[i].first, &a[i].second);

		rx += a[i].first;
		ry += a[i].second;
	}

	rx /= N;
	ry /= N;

	double r = 0;
	for(int i=0; i < N; i++)
		r = max(r, sq(a[i].first - rx) + sq(a[i].second - ry));

	printf("%.8f %.8f %.8f", rx, ry, sqrt(r));
	return 0;
}