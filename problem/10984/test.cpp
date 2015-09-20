#include <iostream>
#include <algorithm>
#include <cstring>
#include <vector>
#include <cstdio>
#include <map>

using namespace std;

int main()
{
	int T;
	cin >> T;

	while(T--)
	{
		int N;
		cin >> N;

		int a = 0;
		double b = 0;

		for(int i=0; i < N; i++)
		{
			int c;
			double d;
			scanf("%d %lf",&c,&d);
			a += c;
			b += c * d;
		}
		printf("%d %.1f\n",a, b / a + 1e-6);
	}

	return 0;
}