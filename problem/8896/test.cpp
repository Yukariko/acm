#include <iostream>
#include <algorithm>

using namespace std;

int main()
{
	int T;
	cin >> T;

	while(T--)
	{
		int N;
		cin >> N;

		string player[N+1];
		for(int i=1; i <= N; i++)
			cin >> player[i];

		int K = player[1].length();

		bool lose[11] = {};
		int lCnt = N;

		for(int i=0; i < K; i++)
		{
			int R,S,P;
			R=S=P=0;

			for(int j=1; j <= N; j++)
			{
				if(lose[j])
					continue;
				if(player[j][i] == 'R')
					R++;
				else if(player[j][i] == 'S')
					S++;
				else
					P++;
			}

			if(R && S && P)
				continue;

			if((!R && !S) || (!S && !P) || (!R && !P))
				continue;

			char selLose;
			if(R == 0)
				selLose = 'P';
			else if(S == 0)
				selLose = 'R';
			else
				selLose = 'S';

			for(int j=1; j <= N; j++)
			{
				if(lose[j])
					continue;
				if(player[j][i] == selLose)
				{
					lCnt--;
					lose[j] = true;
				}
			}
		}
		if(lCnt > 1)
			cout << "0" << endl;
		else
			for(int i=1; i <= N; i++)
				if(lose[i] == false)
					cout << i << endl;

	}
	return 0;
}