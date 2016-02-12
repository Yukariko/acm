#include <bits/stdc++.h>

using namespace std;

const int INF = 987654321;

int main()
{
	int T;
	scanf("%d", &T);

	while(T--)
	{
		int N;
		scanf("%d", &N);

		N += 2;

		int a[103][2];
		for(int i=0; i < N; i++)
			scanf("%d%d", &a[i][0], &a[i][1]);

		int d[103][103];
		for(int i=0; i < N; i++)
		{
			for(int j=0; j < N; j++)
				d[i][j] = INF;
			d[i][i] = 0;
		}

		for(int i=0; i < N; i++)
			for(int j=i+1; j < N; j++)
			{
				int dist = abs(a[i][0] - a[j][0]) + abs(a[i][1] - a[j][1]);
				if(dist <= 1000)
					d[i][j] = d[j][i] = dist;
			}

		for(int k=0; k < N; k++)
			for(int i=0; i < N; i++)
				for(int j=0; j < N; j++)
					d[i][j] = min(d[i][j], d[i][k] + d[k][j]);

		puts(d[0][N-1] != INF? "happy": "sad");
	}
	return 0;
}