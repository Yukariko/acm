#include <bits/stdc++.h>

using namespace std;

const int INF = 987654321;

int a[501][501];
int d[501][501];

int main()
{
	int N;
	scanf("%d",&N);

	for(int i=0; i < N; i++)
	{
		for(int j=0; j < N; j++)
			d[i][j] = INF;
		d[i][i] = 0;
	}

	int ans = 0;
	for(int i=0; i < N; i++)
	{
		for(int j=0; j < N; j++)
		{
			scanf("%d",&a[i][j]);
			ans += a[i][j];
			d[i][j] = a[i][j];
		}
	}

	for(int k=0; k < N; k++)
	{
		for(int i=0; i < N; i++)
			if(k != i)
			{
				for(int j=0; j < N; j++)
					if(k != j)
					{
						if(d[i][j] > d[i][k] + d[k][j])
						{
							d[i][j] = d[i][k] + d[k][j];
						}
					}
			}
	}

	bool eq = true;
	for(int i=0; i < N; i++)
		for(int j=i+1; j < N; j++)
			if(d[i][j] != a[i][j])
				eq = false;

	if(eq == false)
	{
		puts("-1");
		return 0;
	}

	for(int i=0; i < N; i++)
	{
		for(int j=0; j < N; j++)
		{
			for(int k=0; k < N; k++)
			{
				if(k != i && k != j && d[i][j] == d[i][k] + d[k][j])
				{
					ans -= a[i][j];
					break;
				}
			}
		}
	}

	printf("%d\n", ans / 2);
	return 0;
}