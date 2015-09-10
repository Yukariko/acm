#include <iostream>
#include <algorithm>
#include <cstring>
#include <vector>
#include <cstdio>
#include <map>

using namespace std;

const int INF = 987654321;

int main()
{
	int T;
	cin >> T;

	while(T--)
	{
		int a[101][101];
		int b[101][101];
		int M, N, L, G;

		cin >> M >> N >> L >> G;
		for(int i=0; i < M; i++)
			for(int j=0; j < N-1; j++)
				cin >> a[i][j];
		for(int i=0; i < M-1; i++)
			for(int j=0; j < N; j++)
				cin >> b[i][j];


		static int cache[101][101][2][201];
		memset(cache, 10, sizeof(cache));

		cache[0][0][0][0] = cache[0][0][1][0] = 0;
		for(int i=1; i < M; i++)
			cache[i][0][1][0] = cache[i-1][0][1][0] + b[i-1][0];
		
		for(int i=1; i < N; i++)
			cache[0][i][0][0] = cache[0][i-1][0][0] + a[0][i-1];

		for(int i=1; i < M; i++)
		{
			for(int j=1; j < N; j++)
			{
				for(int k=1; k < i+j; k++)
				{
					cache[i][j][0][k] = a[i][j-1] + min(cache[i][j-1][0][k], cache[i][j-1][1][k-1]);
					cache[i][j][1][k] = b[i-1][j] + min(cache[i-1][j][0][k-1], cache[i-1][j][1][k]);
				}
			}
		}
		
		int gas = INF;
		int ans = N+M;
		for(int i=1; i <= N+M; i++)
		{

			gas = min(gas, min(cache[M-1][N-1][0][i], cache[M-1][N-1][1][i]));
			if(min(cache[M-1][N-1][0][i], cache[M-1][N-1][1][i]) <= G)
			{
				ans = i;
				break;
			}
		}

		if(gas > G)
			cout << "-1" << "\n";
		else
			cout << ans + (M + N - 2) * L << '\n';
	}
	return 0;
}