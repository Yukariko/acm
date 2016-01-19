#include <iostream>
#include <algorithm>
#include <cstring>

using namespace std;

int gcd[201][201];

int main()
{
	int T;
	scanf("%d", &T);

	static int cache[201][201][201];
	memset(cache, 0x70, sizeof(cache));

	for(int i=1; i <= 200; i++)
	{
		cache[i][i][i] = 1;
		for(int j=1; j <= 200; j++)
		{
			cache[1][i][j] = i * j;
			cache[i][1][j] = i * j;
			cache[i][j][1] = i * j;
		}
	}

	for(int i=2; i <= 200; i++)
	{
		for(int j=2; j <= 200; j++)
		{
			int e = max(i, j);
			for(int k=2; k <= 200; k++)
			{
				int t = max(e, k) / 2;
				for(int d=1; d <= t; d++)
				{
					if(d < i)
						cache[i][j][k] = min(cache[i][j][k], cache[i-d][j][k] + cache[d][j][k]);
					if(d < j)
						cache[i][j][k] = min(cache[i][j][k], cache[i][j-d][k] + cache[i][d][k]);
					if(d < k)
						cache[i][j][k] = min(cache[i][j][k], cache[i][j][k-d] + cache[i][j][d]);
				}
			}
		}
	}

	while(T--)
	{
		int a[3];
		for(int i=0; i < 3; i++)
			scanf("%d", &a[i]);

		printf("%d\n", cache[a[0]][a[1]][a[2]]);
	}

	return 0;
}