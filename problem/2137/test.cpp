#include <iostream>
#include <cmath>
#include <cstdio>
#include <algorithm>

using namespace std;

int gcd(int p, int q){return q?gcd(q,p%q):p;}

int main()
{
	int A,B;
	cin >> A >> B;

	int ansA, ansB;

	double p = (double)A / B;
	double minSub = 1e10;

	for(int i=0; i <= 32767; i++)
	{
		int start = 1, end = 32767;

		while(start <= end)
		{
			int mid = (start + end) / 2;
			double sub = p - (double)i / mid;
			if(sub && minSub >= std::abs(sub))
			{
				int G = gcd(i, mid);
				if(i / G != A || mid / G != B)
				{
					minSub = std::abs(sub);
					ansA = i / G;
					ansB = mid / G;
				}
			}

			if(sub < 0)
				start = mid + 1;
			else if(sub > 0)
				end = mid - 1;
			else
				break;
		}
	}

	cout << ansA << " " << ansB;
	return 0;
}