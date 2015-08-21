#include <iostream>
#include <algorithm>
#include <cstring>
#include <vector>
#include <cstdio>
#include <map>
#include <queue>

using namespace std;

int N, M;
char a[501][501];

const int dy[] = {1,-1,0,0};
const int dx[] = {0,0,1,-1};

int check(int y, int x)
{
	a[y][x] = 0;
	int ans = 1;
	for(int d=0; d < 4; d++)
	{
		int ny = y + dy[d];
		int nx = x + dx[d];
		if(ny < 0 || ny >= N || nx < 0 || nx >= M || a[ny][nx] != '1')
			continue;

		ans += check(ny,nx);
	}
	return ans;
}

int main()
{	
	cin >> N >> M;
	for(int i=0; i < N; i++)
		for(int j=0; j < M; j++)
			cin >> a[i][j];

	int count = 0;
	int maxArea = 0;
	for(int i=0; i < N; i++)
		for(int j=0; j < M; j++)
			if(a[i][j] == '1')
			{
				count++;
				maxArea = max(maxArea, check(i,j));
			}

	cout << count << endl;
	cout << maxArea << endl;
	return 0;
}