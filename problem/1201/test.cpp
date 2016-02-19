#include <bits/stdc++.h>

using namespace std;

int N, M, K;

bool pick[501];

int main()
{
	scanf("%d%d%d", &N, &M, &K);
	if(M+K > N + 1)
	{
		puts("-1");
		return 0;
	}

	if(N > M * K)
	{
		puts("-1");
		return 0;
	}

	int p = K;
	int lis = 0;
	int low = 1;
	for(int i=0; i < N; )
	{
		lis++;
		for(int j=0; j < K && i < N; j++)
		{
			if(N - i <= M - lis + 1)
			{
				while(i < N)
				{
					printf("%d ", low);
					pick[low] = true;
					while(pick[low])
						low++;
					i++;
				}
				break;
			}

			pick[p-j] = true;
			while(pick[low])
				low++;
			printf("%d ", p -j);
			i++;
		}
		p += K;
	}
	return 0;
}