#include <iostream>
#include <algorithm>
#include <cstring>
#include <vector>
#include <cstdio>
#include <map>

using namespace std;

char a[1<<10][2046];

void solve(int N, int sy, int sx)
{
	if(N == 0)
		return;
	int rangeX = 1;
	for(int i=1; i < N; i++)
		rangeX += 1 << (i + 1);

	int rangeY = (1 << N) - 1;
	int updown = N % 2;

	if(updown)
	{
		for(int i=0; i < rangeX; i++)
			a[sy+rangeY-1][sx+i] = '*';
		for(int i=rangeY-2; i >= 0; i--)
		{
			a[sy+i][sx+rangeY-i-1] = a[sy+i][sx+rangeX-1-(rangeY-i-1)] = '*';
			for(int j=0; j < rangeX-(rangeY-i-1); j++)
				if(a[sy+i][sx+j] == 0)
					a[sy+i][sx+j] = ' ';
		}
	}

	else
	{
		for(int i=0; i < rangeX; i++)
			a[sy][sx+i] = '*';
		for(int i=1; i < rangeY; i++)
		{
			a[sy+i][sx+i] = a[sy+i][sx+rangeX-1-i] = '*';
			for(int j=0; j < rangeX-i; j++)
				if(a[sy+i][sx+j] == 0)
					a[sy+i][sx+j] = ' ';
		}
	}


	if(updown)
		solve(N-1, sy + (1 << (N-1)) - 1, sx + (1 << (N-1)));
	else
		solve(N-1, sy + 1, sx + (1 << (N-1)));
}

int main()
{
	int N;
	cin >> N;
	solve(N, 0, 0);

	for(int i=0; i < (1 << N) - 1; i++)
		cout << a[i] << '\n';
	return 0;
}