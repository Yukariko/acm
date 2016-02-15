#include <bits/stdc++.h>

using namespace std;

int main()
{
	int N;
	double D;
	while(scanf("%d%lf", &N, &D), N)
	{
		int M = (D + 1e-6) * 100;

		int d[10001];
		memset(d, -1, sizeof(d));
		d[0] = 0;

		int ans = 0;

		for(int i=0; i < N; i++)
		{
			int C, P;
			scanf("%d%lf", &C, &D);
			P = (D + 1e-6) * 100;

			for(int j=P; j <= M; j++)
				if(d[j-P] != -1)
				{
					d[j] = max(d[j], d[j-P] + C);
					ans = max(ans, d[j]);
				}
		}

		printf("%d\n", ans);
	}
	return 0;
}