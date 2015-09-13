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
	scanf("%d",&T);

	while(T--)
	{
		int K, N;
		scanf("%d%d",&K,&N);

		static int a[4][1001];
		for(int i=0; i < 4; i++)
			for(int j=0; j < N; j++)
				scanf("%d",&a[i][j]);

		vector<int> q;
		for(int i=0; i < N; i++)
			for(int j=0; j < N; j++)
				q.push_back(a[0][i] + a[1][j]);

		sort(q.begin(), q.end());

		vector<int> p;
		p.push_back(q[0]);
		for(int i=1; i < q.size(); i++)
			if(q[i] != q[i-1])
				p.push_back(q[i]);

		int near = 987654321;
		int ans = 987654321;

		for(int i=0; i < N; i++)
		{
			for(int j=0; j < N; j++)
			{
				int n = a[2][i] + a[3][j];
				vector<int>::iterator low = lower_bound(p.begin(), p.end(), K - n);

				if(abs(K - *low - n) <= near)
				{
					if(abs(K - *low - n) == near)
						ans = min(ans, *low + n);
					else
					{
						near = abs(K - *low - n);
						ans = *low + n;
					}
				}
				if(low != p.begin())
				{
					if(abs(K - *(low-1) - n) <= near)
					{
						if(abs(K - *(low-1) - n) == near)
							ans = min(ans, *(low-1) + n);
						else
						{
							near = abs(K - *(low-1) - n);
							ans = *(low-1) + n;
						}
					}
				}
			}
		}
		printf("%d\n",ans);
	}
	return 0;
}