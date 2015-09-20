#include <iostream>
#include <algorithm>
#include <cstring>
#include <vector>
#include <cstdio>
#include <map>

using namespace std;

char a[501][501];

int main()
{
	int N;
	cin >> N;
	if(N == 1)
	{
		cout << "*";
		return 0;
	}

	int rN = 4 * (N-1) + 1;
	for(int i=0; i < rN+2; i++)
		for(int j=0; j < rN; j++)
			a[i][j] = ' ';


	int x = rN-1, y = 0;
	int dx = -1, dy = 0;
	int cnt = 0;
	int level = rN + 1;
	int curPos = 2;

	while(level)
	{
		a[y][x] = '*';
		y += dy;
		x += dx;

		curPos++;
		if(curPos == level)
		{
			curPos = 0;
			int t = dx;
			dx = dy;
			dy = -t;

			cnt++;
			if(cnt == 2)
			{
				cnt = 0;
				level -= 2;
			}
		}

	}

	a[y][x] = '*';
	for(int i=0; i < rN + 2; i++)
	{
		int star = 0;
		for(int j=0; j < rN; j++)
			star += a[i][j] == '*';

		for(int j=0; j < rN && star; j++)
		{
			star -= a[i][j] == '*';
			cout << a[i][j];
		}
		puts("");
	}
	return 0;
}