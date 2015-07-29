#include <iostream>
#include <cstdio>
#include <algorithm>

using namespace std;

int main()
{
	int T;
	scanf("%d",&T);

	while(T--)
	{
		int N;
		scanf("%d",&N);

		int absN = abs(N);
		
		int base = 1;
		int sum = 1;
		while(sum < absN)
		{
			base *= 3;
			sum += base;
		}

		int num = N;
		while(base)
		{
			sum -= base;
			
			if(sum < num)
			{
				putchar('1');
				num -= base;
			}
			else if(abs(num) <= sum)
				putchar('0');
			else
			{
				putchar('-');
				num += base;
			}

			base /= 3;
		}

		puts("");
	}

	return 0;
}