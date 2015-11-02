#include <bits/stdc++.h>

using namespace std;

int limit[] = {0, 200, limit[1] + 9900 * 3, limit[2] + 990000 * 5};
int decimal[] = {0, 100, 10000, 1000000};
int weight[] = {2, 3, 5, 7};

int getWatt(int N)
{
	for(int i=3; i >= 0; i--)
		if(N >= limit[i])
			return decimal[i] + (N - limit[i]) / weight[i];
	return -1;
}

int getMoney(int N)
{
	for(int i=3; i >= 0; i--)
		if(N > decimal[i])
			return limit[i] + (N - decimal[i]) * weight[i];
	return -1;
}

int main()
{
	int A, B;
	while(scanf("%d%d",&A,&B), A)
	{
		int watt = getWatt(A);

		int start = 0, end = watt;
		while(start <= end)
		{
			int mid = (start + end) / 2;
			int r = getMoney(watt-mid);
			int l = getMoney(mid);
			if(r == B + l)
			{
				printf("%d\n", min(l,r));
				break;
			}

			if(r > B + l)
				start = mid + 1;
			else
				end = mid - 1;
		}
	}

	return 0;
}