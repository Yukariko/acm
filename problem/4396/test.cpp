#include <bits/stdc++.h>

using namespace std;

const int dy[] = {1, 1, 1, -1, -1, -1, 0, 0};
const int dx[] = {-1, 0, 1, -1, 0, 1, -1, 1};

int N;
char a[11][11];
char b[11][11];

int getStar(int y, int x)
{
	int star = 0;
	for(int d=0; d < 8; d++)
	{
		int ny = y + dy[d];
		int nx = x + dx[d];
		if(ny < 0 || ny >= N || nx < 0 || nx >= N || a[ny][nx] != '*')
			continue;
		star++;
	}
	return star;
}

int main()
{
	scanf("%d", &N);
	for(int i=0; i < N; i++)
		scanf("%s", a[i]);
	for(int i=0; i < N; i++)
		scanf("%s", b[i]);

	bool die = false;
	for(int i=0; i < N; i++)
		for(int j=0; j < N; j++)
			die |= b[i][j] == 'x' && a[i][j] == '*';

	for(int i=0; i < N; i++)
	{
		for(int j=0; j < N; j++)
			if(die && a[i][j] == '*')
				putchar('*');
			else if(b[i][j] == '.')
				putchar('.');
			else
				putchar('0' + getStar(i, j));
		puts("");
	}
	return 0;
}