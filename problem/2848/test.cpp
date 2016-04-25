#include <bits/stdc++.h>

using namespace std;

const int INF = 987654321;

int main()
{
	int N;
	scanf("%d", &N);

	char a[101][11];
	for(int i=0; i < N; i++)
		scanf("%s", a[i]);

	int adj[26][26];
	fill(&adj[0][0], &adj[26][0], INF);
	for(int i=0; i < N; i++)
		for(int j=i+1; j < N; j++)
			for(int k=0; a[i][k] && a[j][k]; k++)
				if(a[i][k] != a[j][k])
				{
					adj[a[i][k] - 'a'][a[j][k] - 'a'] = 1;
					break;
				}

	bool used[26] = {};
	for(int i=0; i < N; i++)
		for(int j=0; a[i][j]; j++)
			used[a[i][j] - 'a'] = true;

	int num = 0;
	for(int i=0; i < 26; i++)
		if(used[i])
			num++;

	for(int k=0; k < 26; k++)
		for(int i=0; i < 26; i++)
			for(int j=0; j < 26; j++)
				adj[i][j] = min(adj[i][j], adj[i][k] + adj[k][j]);				

	for(int i=0; i < 26; i++)
		for(int j=i+1; j < 26; j++)
			if(adj[i][j] != INF && adj[j][i] != INF)
				return puts("!"), 0;

	char rank[26] = {};
	for(int i=0; i < 26; i++)
	{
		if(!used[i])
			continue;
		int up = 0;
		int down = 0;
		for(int j=0; j < 26; j++)
		{
			if(adj[j][i] != INF)
				up++;
			if(adj[i][j] != INF)
				down++;
		}

		if(up + down + 1 != num)
			return puts("?"), 0;
		rank[up] = i + 'a';
	}

	for(int i=0; i < 26; i++)
		if(rank[i])
			putchar(rank[i]);
	return 0;
}