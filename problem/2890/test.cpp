#include <bits/stdc++.h>

using namespace std;

int main()
{
	int R, C;
	scanf("%d%d", &R, &C);

	char a[51][51];
	for(int i=0; i < R; i++)
		scanf("%s", a[i]);

	vector<int> winner[51];
	for(int i=0; i < R; i++)
		for(int j=C-2; j > 0; j--)
			if(a[i][j] != '.')
			{
				winner[j].push_back(a[i][j]-'0');
				j-=2;
			}

	vector<int> grade(10);

	int rank = 1;
	for(int i=C-2; i > 0; i--)
	{
		if(!winner[i].empty())
		{
			while(!winner[i].empty())
			{
				grade[winner[i].back()] = rank;
				winner[i].pop_back();
			}
			rank++;
		}
	}

	for(int i=1; i <= 9; i++)
		printf("%d\n", grade[i]);

	return 0;
}