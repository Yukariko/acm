#include <bits/stdc++.h>

using namespace std;

int main()
{
	int N, M;
	scanf("%d%d",&N,&M);

	int result[101];
	for(int i=0; i < M; i++)
		scanf("%d",&result[i]);

	int score[101] = {};
	for(int i=0; i < M; i++)
	{
		int plus = 0;
		for(int j=0; j < N; j++)
		{
			int ans;
			scanf("%d",&ans);
			if(result[i] == ans)
				score[j]++;
			else
				plus++;
		}
		score[result[i]-1] += plus;
	}

	for(int i=0; i < N; i++)
		printf("%d\n", score[i]);
	return 0;
}