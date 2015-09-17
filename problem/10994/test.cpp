#include <iostream>
#include <algorithm>
#include <cstring>
#include <vector>
#include <cstdio>
#include <map>

using namespace std;

char a[501][501] = {};

int main()
{
	int N;
	cin >> N;

	for(int i=0; i < 501; i++)
		memset(a[i], ' ', sizeof(a[i]));

	for(int i=0; i < N; i++)
	{
		int y = (N - i - 1) * 2, x = (N - i - 1) * 2 , l = i * 4 + 1;
		for(int j=0; j < l; j++)
			a[y][x+j] = '*';
		for(int j=0; j < l; j++)
			a[y+l-1][x+j] = '*';
		for(int j=1; j < l; j++)
			a[y+j][x] = '*';
		for(int j=1; j < l; j++)
			a[y+j][x+l-1] = '*';

	}

	for(int i=0; i < (N-1) * 4 + 1; i++)
	{
		for(int j=0; j < (N-1) * 4 + 1; j++)
			cout << a[i][j];
		cout << '\n';
	}
	return 0;
}