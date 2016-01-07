#include <bits/stdc++.h>

using namespace std;

int N, M;
char a[101][101];
long long sum[101][101];

long long calc(int sy, int sx, int ey, int ex)
{
	long long l = 0, r = 0, m = 0;
	if(sx > 0)
		l = sum[ey-1][sx-1];
	if(sy > 0)
		r = sum[sy-1][ex-1];
	if(sy > 0 && sx > 0)
		m = sum[sy-1][sx-1];
	return sum[ey-1][ex-1] - l - r + m;
}

long long solve(int depth, int sy, int sx, int ey, int ex)
{
	if(depth == 2)
		return calc(sy, sx, ey, ex);

	long long ans = 0;
	for(int i=sy + 1; i < ey; i++)
	{
		ans = max(ans, calc(sy, sx, i, ex) * solve(depth+1, i, sx, ey, ex));
		ans = max(ans, calc(i, sx, ey, ex) * solve(depth+1, sy, sx, i, ex));
	}

	for(int i=sx + 1; i < ex; i++)
	{
		ans = max(ans, calc(sy, sx, ey, i) * solve(depth+1, sy, i, ey, ex));
		ans = max(ans, calc(sy, i, ey, ex) * solve(depth+1, sy, sx, ey, i));
	}

	return ans;
}

int main()
{
	scanf("%d%d",&N,&M);
	for(int i=0; i < N; i++)
		scanf("%s",a[i]);

	sum[0][0] = a[0][0] - '0';
	for(int i=1; i < N; i++)
		sum[i][0] = sum[i-1][0] + a[i][0] - '0';
	for(int i=1; i < M; i++)
		sum[0][i] = sum[0][i-1] + a[0][i] - '0';

	for(int i=1; i < N; i++)
		for(int j=1; j < M; j++)
			sum[i][j] = sum[i-1][j] + sum[i][j-1] - sum[i-1][j-1] + a[i][j] - '0';

	printf("%lld", solve(0, 0, 0, N, M));
	return 0;
}