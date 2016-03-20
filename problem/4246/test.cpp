#include <bits/stdc++.h>

using namespace std;

int main()
{
	int N;
	char a[201];
	while(scanf("%d", &N), N)
	{
		scanf("%s", a);
		char b[21][201] = {};
		int row = 0;
		int column = 0;
		for(int i=0; a[i]; i++)
		{
			b[row][column] = a[i];
			if(i % N == N-1)
			{
				column += row & 1? -1: 1;
				row++;
			}
			column += row & 1? -1: 1;
		}

		for(int i=0; i < N; i++)
			for(int j=0; b[j][i]; j++)
				putchar(b[j][i]);
		puts("");
	}
	return 0;
}