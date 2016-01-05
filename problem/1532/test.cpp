#include <bits/stdc++.h>

using namespace std;

int main()
{

	long long G, A, T, D;
	while(scanf("%lld%lld%lld%lld",&G,&T,&A,&D), G != -1)
	{
		long long X, Y = G * A + D;

		long long near = 1;
		while(near < Y)
			near *= 2;

		Y = near - Y;

		X = T * (T - 1) * G / 2 + near - 1;

		printf("%lld*%lld/%lld+%lld=%lld+%lld\n", G, A, T, D, X, Y);
	}
	return 0;
}