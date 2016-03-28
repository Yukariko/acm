#include <bits/stdc++.h>

using namespace std;

const int dy[] = {1, 1, 1, -1, -1, -1, 0, 0};
const int dx[] = {-1, 0, 1, -1, 0, 1, -1, 1};

int N;
char a[101][101];

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

	if(N < 3)
	{
		puts("0");
		return 0;
	}

	for(int i=0; i < N; i++)
		scanf("%s", a[i]);

	for(int i=0; i < N-2; i++)
	{
		if(a[1][i+1] != '#')
			continue;
		int star = getStar(0, i);
		if(star + '0' < a[0][i])
			a[1][i+1] = '*';
		else
			a[1][i+1] = '.';
	}

	for(int i=0; i < N-2; i++)
	{
		if(a[i+1][1] != '#')
			continue;
		int star = getStar(i, 0);
		if(star + '0' < a[i][0])
			a[i+1][1] = '*';
		else
			a[i+1][1] = '.';
	}

	for(int i=0; i < N-2; i++)
	{
		if(a[i+1][N-2] != '#')
			continue;
		int star = getStar(i, N-1);
		if(star + '0' < a[i][N-1])
			a[i+1][N-2] = '*';
		else
			a[i+1][N-2] = '.';
	}

	for(int i=0; i < N-2; i++)
	{
		if(a[N-2][i+1] != '#')
			continue;
		int star = getStar(N-1, i);
		if(star + '0' < a[N-1][i])
			a[N-2][i+1] = '*';
		else
			a[N-2][i+1] = '.';
	}

	int ans = 0;
	for(int i=0; i < N; i++)
		for(int j=0; j < N; j++)
			ans += a[i][j] == '#' || a[i][j] == '*';
	printf("%d", ans);
	return 0;
}