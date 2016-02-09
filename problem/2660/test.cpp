#include <bits/stdc++.h>

using namespace std;

const int INF = 987654321;

int main()
{
	int N;
	scanf("%d", &N);

	int d[51][51];
	for(int i=1; i <= N; i++)
	{
		for(int j=1; j <= N; j++)
			d[i][j] = INF;
		d[i][i] = 0;
	}

	int u, v;
	while(scanf("%d%d", &u, &v), u != -1)
	{
		d[u][v] = 1;
		d[v][u] = 1;
	}

	for(int k=1; k <= N; k++)
		for(int i=1; i <= N; i++)
			for(int j=1; j <= N; j++)
				d[i][j] = min(d[i][j], d[i][k] + d[k][j]);

	int minScore = N;
	vector<int> elected;
	for(int i=1; i <= N; i++)
	{
		int score = 0;
		for(int j=1; j <= N; j++)
			score = max(score, d[i][j]);

		if(minScore > score)
		{
			minScore = score;
			elected.clear();
		}
		if(minScore == score)
			elected.push_back(i);
	}

	printf("%d %d\n", minScore, elected.size());
	for(int i=0; i < elected.size(); i++)
		printf("%d ", elected[i]);
	return 0;
}