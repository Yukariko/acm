#include <cstdlib>
#include <iostream>
#include <ctime>
using namespace std;

const int dy[] = {0,0,1,-1};
const int dx[] = {1,-1,0,0};

int main()
{
	int R, C;
	cin >> R >> C;

	char m[11][11];
	for(int i=0; i < R; i++)
		cin >> m[i];

	for(int i=0; i < R; i++)
		for(int j=0; j < C; j++)
		{
			if(m[i][j] == 'X')
				continue;
			int canGo = 0;
			for(int d=0; d < 4; d++)
			{
				int y = i + dy[d];
				int x = j + dx[d];
				if(y < 0 || y >= R || x < 0 || x >= C || m[y][x] == 'X')
					continue;
				canGo++;
			}

			if(canGo <= 1)
			{
				cout << 1;
				return 0;
			}
		}

	cout << 0;
	return 0;
}