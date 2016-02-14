#include <bits/stdc++.h>

using namespace std;

const int INF = 987654321;

int main()
{
	int N;
	scanf("%d", &N);

	int d[52][52];
	for(int i=0; i < 52; i++)
	{
		for(int j=0; j < 52; j++)
			d[i][j] = INF;
		d[i][i] = 0;
	}

	while(N--)
	{
		char u, v;
		scanf(" %c %*s %c", &u, &v);

		u = u >= 'a'? u - 'a' + 26: u - 'A';
		v = v >= 'a'? v - 'a' + 26: v - 'A';
		d[u][v] = 1;
	}

	for(int k=0; k < 52; k++)
		for(int i=0; i < 52; i++)
			for(int j=0; j < 52; j++)
				d[i][j] = min(d[i][j], d[i][k] + d[k][j]);

	int ans = 0;
	for(int i=0; i < 52; i++)
		for(int j=0; j < 52; j++)
			if(i != j && d[i][j] != INF)
				ans++;

	printf("%d\n", ans);

	for(int i=0; i < 52; i++)
		for(int j=0; j < 52; j++)
			if(i != j && d[i][j] != INF)
				printf("%c => %c\n", i < 26? i + 'A': i - 26 + 'a', j < 26? j + 'A': j - 26 + 'a');
	return 0;
}