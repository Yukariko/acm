#include <bits/stdc++.h>

using namespace std;

char a[101], b[101];

int score[127][127];

int main()
{
	score['R']['S'] = 1;
	score['S']['R'] = -1;
	score['P']['R'] = 1;
	score['R']['P'] = -1;
	score['S']['P'] = 1;
	score['P']['S'] = -1;

	while(gets(a), gets(b), a[0] != 'E')
	{
		int aWin = 0, bWin = 0;
		for(int i=0; a[i]; i++)
		{
			if(score[a[i]][b[i]] == 1)
				aWin++;
			else if(score[a[i]][b[i]] == -1)
				bWin++;
		}

		printf("P1: %d\n", aWin);
		printf("P2: %d\n", bWin);
	}
	return 0;
}