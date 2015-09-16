#include <iostream>
#include <algorithm>
#include <cstring>
#include <vector>
#include <cstdio>
#include <map>

using namespace std;

char board[101][101];
char new_board[101][101];


int main()
{
	int H, W;
	cin >> H >> W;

	for(int i=0; i < H; i++)
		cin >> board[i];

	int ans[101][101];
	memset(ans, -1, sizeof(ans));

	for(int t=0; ; t++)
	{
		int cnt = 0;
		memset(new_board, '.', sizeof(new_board));
		for(int i=0; i < H; i++)
		{
			for(int j=0; j < W; j++)
			{
				if(board[i][j] == 'c')
				{
					if(ans[i][j] == -1)
						ans[i][j] = t;
					cnt++;
					if(j != W-1)
					{
						new_board[i][j+1] = 'c';
					}
				}
			}
		}

		if(cnt == 0)
			break;

		memcpy(board, new_board, sizeof(new_board));
	}

	for(int i=0; i < H; i++)
	{
		for(int j=0; j < W; j++)
			cout << ans[i][j] << " ";
		cout << '\n';
	}
	return 0;
}