#include <bits/stdc++.h>

using namespace std;

int N, M, K;
char a[101][101];

int getFly(int y, int x)
{
	int ans = 0;
	for(int i=1; i < K - 1; i++)
		for(int j=1; j < K - 1; j++)
			if(a[y+i][x+j] == '*')
				ans++;
	return ans;
}

int main()
{
	scanf("%d%d%d", &N, &M, &K);
	for(int i=0; i < N; i++)
		scanf("%s", a[i]);

	int ans = 0;
	pair<int, int> pos;
	for(int i=K; i <= N; i++)
		for(int j=K; j <= M; j++)
		{
			int get = getFly(i-K, j-K);
			if(ans < get)
			{
				ans = get;
				pos = {i-K, j-K};
			}
		}

	for(int i=0; i < K; i++)
	{
		a[pos.first + i][pos.second] = '|';
		a[pos.first + i][pos.second + K - 1] = '|';
		a[pos.first][pos.second + i] = '-';
		a[pos.first + K - 1][pos.second + i] = '-';
	}
	a[pos.first][pos.second] = '+';
	a[pos.first + K - 1][pos.second] = '+';
	a[pos.first][pos.second + K - 1] = '+';
	a[pos.first + K - 1][pos.second + K - 1] = '+';
	
	printf("%d\n", ans);
	for(int i=0; i < N; i++)
		puts(a[i]);
	return 0;
}