#include <stdio.h>
#include <iostream>
#include <algorithm>

using namespace std;

bool visit[10];

const int trans[] = {
	448,56,7,292,146,73,273,84
};

const int INF = 987654321;

int solve(int state)
{
	if(state == 511 || state == 0)
		return 0;

	int ret = INF;
	for(int i=0; i < 8; i++)
	{
		if(visit[i] == false)
		{
			visit[i] = true;
			ret = min(ret, 1 + solve(state ^ trans[i]));
			visit[i] = false;
		}
	}
	return ret;
}

int main()
{
	int T;
	cin >> T;
	while(T--)
	{
		int N = 0;
		for(int i=0; i < 9; i++)
		{
			char C;
			cin >> C;

			N <<= 1;
			N += C == 'T';
		}
		int ans = solve(N);
		cout << (ans == INF? -1: ans) << endl;
	}
	return 0;
}