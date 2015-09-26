#include <iostream>
#include <algorithm>
#include <queue>
#include <cstdio>

using namespace std;

#define MAX_N 100000
#define DIVIDE 1000

int findDVD[MAX_N+1];
int a[MAX_N+1];

int main()
{
	int T;
	scanf("%d",&T);

	while(T--)
	{
		int N, M;
		scanf("%d%d",&N,&M);

		
		for(int i=0; i < N; i++)
		{
			a[i] = i;
			findDVD[i] = i;
		}

		priority_queue<int> pack[MAX_N / DIVIDE + 1][2];
		for(int i=0; i < N; i+=DIVIDE)
		{
			int E = min(i+DIVIDE, N);
			for(int j=i; j < E; j++)
			{
				pack[i/DIVIDE][0].push(-a[j]);
				pack[i/DIVIDE][1].push(a[j]);
			}
		}

		while(M--)
		{
			int O, A, B;
			scanf("%d%d%d",&O, &A, &B);

			if(O == 0)
			{
				pack[A/DIVIDE][0].push(-a[B]);
				pack[A/DIVIDE][1].push(a[B]);
				pack[B/DIVIDE][0].push(-a[A]);
				pack[B/DIVIDE][1].push(a[A]);
				findDVD[a[A]] = B;
				findDVD[a[B]] = A;
				swap(a[A],a[B]);
			}
			else
			{
				int mi=1000000001, ma=0;
				int E = min(B+1, (A + DIVIDE) / DIVIDE * DIVIDE);
				for(int i=A; i < E; i++)
				{
					mi = min(mi, a[i]);
					ma = max(ma, a[i]);
				}

				if(E == B+1)
				{
					if(mi == A && ma == B)
						puts("YES");
					else
						puts("NO");
					continue;
				}

				E = B / DIVIDE;
				for(int i=A/DIVIDE+1; i < E; i++)
				{
					while(findDVD[-pack[i][0].top()] < i * DIVIDE || findDVD[-pack[i][0].top()] >= (i+1) * DIVIDE)
						pack[i][0].pop();

					while(findDVD[pack[i][1].top()] < i * DIVIDE || findDVD[pack[i][1].top()] >= (i+1) * DIVIDE)
						pack[i][1].pop();

					mi = min(mi, -pack[i][0].top());
					ma = max(ma, pack[i][1].top());
				}

				for(int i=B/DIVIDE*DIVIDE; i <= B; i++)
				{
					mi = min(mi, a[i]);
					ma = max(ma, a[i]);
				}

				if(mi == A && ma == B)
					puts("YES");
				else
					puts("NO");
			}
		}
	}
	return 0;
}