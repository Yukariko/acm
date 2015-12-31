#include <bits/stdc++.h>

using namespace std;

const int INF = 987654321;

int main()
{
	int N, M;
	scanf("%d%d",&N,&M);

	int a[201][201];
	for(int i=0; i < N; i++)
		for(int j=0; j < N; j++)
			scanf("%d",&a[i][j]);

	int d[201][201] = {};
	for(int i=0; i < N; i++)
	{
		for(int j=0; j < N; j++)
			if(a[i][j] == 0)
				d[i][j] = INF;
			else
				d[i][j] = 1;
		d[i][i] = 0;
	}

	for(int k=0; k < N; k++)
		for(int i=0; i < N; i++)
			for(int j=0; j < N; j++)
				if(d[i][j] > d[i][k] + d[k][j])
					d[i][j] = d[i][k] + d[k][j];

	int pos;
	scanf("%d",&pos);
	pos--;

	while(M--)
	{
		int next;
		scanf("%d",&next);
		next--;
		
		if(d[pos][next] == INF)
		{
			puts("NO");
			return 0;
		}
	}
	puts("YES");
	return 0;
}