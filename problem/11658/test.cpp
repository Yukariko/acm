#include <bits/stdc++.h>

using namespace std;

const int MAX_N = 1024;

int N, M;
int t[MAX_N * 2][MAX_N * 2];

void build()
{
	for(int i=2*N-1; i >= N; i--)
		for(int j=N-1; j > 0; j--)
			t[i][j] = t[i][j<<1] + t[i][j<<1|1];
	for(int i=N-1; i > 0; i--)
		for(int j=2*N-1; j >= N; j--)
			t[i][j] = t[i<<1][j] + t[i<<1|1][j];
	for(int i=N-1; i > 0; i--)
		for(int j=N-1; j > 0; j--)
			t[i][j] = t[i<<1][j<<1] + t[i<<1][j<<1|1] + t[i<<1|1][j<<1] + t[i<<1|1][j<<1|1];
}

void modify(int h, int w, int val)
{
	t[h+=N][w+=N] = val;
	for(int y=h; y > 1; y >>= 1)
		t[y>>1][w] = t[y][w] + t[y^1][w];
	for(int x=w; x > 1; x >>= 1)
		t[h][x>>1] = t[h][x] + t[h][x^1];
	for(; h > 1; h >>= 1)
		for(int tw = w; tw > 1; tw >>= 1)
			t[h>>1][tw>>1] = t[h][tw] + t[h][tw^1] + t[h^1][tw] + t[h^1][tw^1];
}

int query(int yl, int yr, int xl, int xr)
{
	int res = 0;
	for(yl += N, yr += N; yl < yr; yl >>= 1, yr >>= 1)
	{
		if(yl & 1)
		{
			for(int l = xl + N, r = xr + N; l < r; l >>= 1, r >>= 1)
			{
				if(l & 1)
					res += t[yl][l++];
				if(r & 1)
					res += t[yl][--r];
			}
			yl++;
		}
		if(yr & 1)
		{
			yr--;
			for(int l = xl + N, r = xr + N; l < r; l >>= 1, r >>= 1)
			{
				if(l & 1)
					res += t[yr][l++];
				if(r & 1)
					res += t[yr][--r];
			}
		}
	}
	return res;
}

int main()
{
	scanf("%d%d", &N, &M);
	for(int i=0; i < N; i++)
		for(int j=0; j < N; j++)
			scanf("%d", &t[i + N][j + N]);

	build();

	while(M--)
	{
		int C, X1, Y1, X2, Y2, R;
		scanf("%d%d%d", &C, &X1, &Y1);

		if(C == 0)
		{
			scanf("%d", &R);
			modify(X1-1, Y1-1, R);
		}
		else
		{
			scanf("%d%d", &X2, &Y2);
			if(X2 < X1)
				swap(X2, X1);
			if(Y2 < Y1)
				swap(Y2, Y1);
			printf("%d\n", query(X1-1, X2, Y1-1, Y2));
		}
	}
	return 0;
}