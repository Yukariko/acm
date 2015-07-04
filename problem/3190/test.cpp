#include <iostream>
#include <algorithm>

using namespace std;

int main()
{
	int N,K;
	char map[102][102] = {};

	cin >> N >> K;
	for(int i=0; i < K; i++)
	{
		int Y,X;
		cin >> Y >> X;
		map[Y][X] = 1;
	}

	for(int i=0; i <= N+1; i++)
		map[0][i] = map[i][0] = map[N+1][i] = map[i][N+1] = 2;

	int L;
	cin >> L;

	int y = 1, x = 1;
	int len = 1;
	int tail[101][2] = {};
	int dx = 1, dy = 0;

	map[1][1] = 3;
	tail[0][0] = y;
	tail[0][1] = x;

	int ret = 0;
	L++;
	while(L--)
	{
		int X;
		char C;
		if(L > 0)
		{
			cin >> X >> C;
			X -= ret;
		}
		else
			X = 101;
		while(X--)
		{
			ret++;
			x += dx;
			y += dy;

			int ey = tail[len-1][0];
			int ex = tail[len-1][1];

			for(int i=len-1; i > 0; i--)
			{
				tail[i][0] = tail[i-1][0];
				tail[i][1] = tail[i-1][1];
			}
			tail[0][0] = y;
			tail[0][1] = x;

			if(map[y][x] == 2 || map[y][x] == 3)
				break;
			
			map[ey][ex] = 0;
			if(map[y][x] == 1)
			{
				tail[len][0] = ey;
				tail[len++][1] = ex;
				map[ey][ex] = 3;
			}

			map[y][x] = 3;
		}
		if(X != -1)
			break;

		if(C == 'D')
		{
			int t = dx;
			dx = -dy;
			dy = t;
		}
		else
		{
			int t = dx;
			dx = dy;
			dy = -t;
		}
	}

	cout << ret;
	return 0;
}