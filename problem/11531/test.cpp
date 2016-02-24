#include <bits/stdc++.h>

using namespace std;

int main()
{
	int M;
	map<char, int> ck;

	int score = 0, solvedProblem = 0;
	while(scanf("%d", &M), M != -1)
	{
		char problem;
		char answer[10];
		scanf(" %c%s", &problem, answer);

		if(strcmp(answer, "wrong") == 0)
			ck[problem]++;
		else
		{
			score += ck[problem] * 20 + M;
			solvedProblem++;
		}
	}

	printf("%d %d", solvedProblem, score);
	return 0;
}