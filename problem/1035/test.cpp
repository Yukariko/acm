#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;

char a[5][6];
int num;

const int dy[] = {1,-1,0,0};
const int dx[] = {0,0,1,-1};

#define IDX(y,x) (1 << (y * 5 + x))

int getIdx()
{
	int ans = 0;
	for(int i=0; i < 5; i++)
		for(int j=0; j < 5; j++)
			if(a[i][j] == '*')
				ans |= IDX(i,j);
	return ans;
}

bool isOK(int board, int y, int x)
{
	return !(y < 0 || y >= 5 || x < 0 || x >= 5 || (board & IDX(y,x)));
}

char cache[1<<25];

void precalc(int board, int pos)
{
	if(pos == num)
	{
		cache[board] = 0;
		return;
	}

	for(int i=0; i < 5; i++)
	{
		for(int j=0; j < 5; j++)
		{
			if((board & IDX(i,j)) == 0)
				continue;
			for(int d=0; d < 4; d++)
			{
				int Y = i + dy[d];
				int X = j + dx[d];
				if(isOK(board, Y, X))
					precalc(board | IDX(Y,X), pos+1);
			}
		}
	}
}

char solve(int board)
{
	char& ret = cache[board];
	if(ret != -1)
		return ret;

	ret = 100;
	for(int i=0; i < 5; i++)
	{
		for(int j=0; j < 5; j++)
		{
			if((board & IDX(i,j)) == 0)
				continue;
			for(int d=0; d < 4; d++)
			{
				const int y = i + dy[d];
				const int x = j + dx[d];
				if(isOK(board, y, x))
					ret = min(ret, (char)(1 + solve((board & ~IDX(i,j)) | IDX(y,x))));
			}
		}
	}

	return ret;
}

int main()
{
	memset(cache, -1, sizeof(cache));

	for(int i=0; i < 5; i++)
		cin >> a[i];

	for(int i=0; i < 5; i++)
		for(int j=0; j < 5; j++)
			if(a[i][j] == '*')
				num++;

	for(int i=0; i < 5; i++)
		for(int j=0; j < 5; j++)
			precalc(IDX(i,j),1);

	cout << (int)solve(getIdx());
	return 0;
}