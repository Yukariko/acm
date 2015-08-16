#include <iostream>
#include <algorithm>

using namespace std;

const int dy[] = {1,-1,0,0};
const int dx[] = {0,0,1,-1};

int a[5][5];
bool visit[1000000];

int solve(int depth, const int& y, const int& x, int num)
{
	if(depth == 6)
	{
		if(visit[num])
			return 0;
		return visit[num] = true;
	}

	int ans = 0;
	for(int d=0; d < 4; d++)
	{
		int Y = y + dy[d];
		int X = x + dx[d];
		if(Y < 0 || Y >= 5 || X < 0 || X >= 5)
			continue;

		ans += solve(depth+1, Y, X, num * 10 + a[y][x]);
	}
	return ans;
}

int main()
{
	for(int i=0; i < 5; i++)
		for(int j=0; j < 5; j++)
			cin >> a[i][j];

	int ans = 0;
	for(int i=0; i < 5; i++)
		for(int j=0; j < 5; j++)
			ans += solve(0,i,j,0);

	cout << ans;
	return 0;
}