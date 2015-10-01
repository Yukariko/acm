#include <bits/stdc++.h>

using namespace std;

#define X(x) (x + 500000)

int N;
int a[51];
int d[2][1000001];

int main()
{
	scanf("%d",&N);
	for(int i=0; i < N; i++)
		scanf("%d",&a[i]);

	memset(d,-1,sizeof(d));

	int ans = -1;
	d[0][X(a[0])] = a[0];
	d[0][X(-a[0])] = 0;
	d[0][X(0)] = 0;
	for(int i=1; i < N; i++)
	{
		for(int j=-500000; j <= 500000; j++)
		{
			d[i&1][X(j)] = d[!(i&1)][X(j)];
			if(X(j - a[i]) >= 0 && d[!(i&1)][X(j - a[i])] != -1)
				d[i&1][X(j)] = max(d[i&1][X(j)], d[!(i&1)][X(j - a[i])] + a[i]);
			if(X(j + a[i]) <= 1000000 && d[!(i&1)][X(j + a[i])] != -1)
				d[i&1][X(j)] = max(d[i&1][X(j)], d[!(i&1)][X(j + a[i])]);
			if(j == 0)
				ans = max(ans, d[i&1][X(j)]);
		}
	}

	printf("%d",ans == 0? -1: ans);
	return 0;
}