// floyd
#include <bits/stdc++.h>

using namespace std;

int main()
{
	int N, M;
	scanf("%d%d", &N, &M);

	int d[501][501];
	for(int i=0; i < N; i++)
		for(int j=0; j < N; j++)
			scanf("%d", &d[i][j]);

	for(int k=0; k < N; k++)
		for(int i=0; i < N; i++)
			for(int j=0; j < N; j++)
				d[i][j] = min(d[i][j], d[i][k] + d[k][j]);

	while(M--)
	{
		int u, v, w;
		scanf("%d%d%d", &u, &v, &w);
		u--, v--;
		puts(d[u][v] <= w? "Enjoy other party": "Stay here");
	}
	return 0;
}