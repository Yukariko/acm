#include <bits/stdc++.h>

using namespace std;

const int percent[] = {15, 20, 25, 40};

int main()
{
	int T;
	scanf("%d", &T);

	while(T--)
	{
		int a[3];
		for(int i=0; i < 3; i++)
			scanf("%d", &a[i]);

		int sum = 0;
		for(int i=0; i < 3; i++)
			sum += a[i] * percent[i];

		if(90 * 100 - sum > 100 * percent[3])
			puts("impossible");
		else
			printf("%d\n", (90 * 100 - sum + percent[3] - 1) / percent[3]);
	}
	return 0;
}