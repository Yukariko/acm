#include <iostream>
#include <algorithm>
#include <cstring>
#include <vector>
#include <cstdio>
#include <stack>

using namespace std;

int main()
{
	int T;
	cin >> T;

	int ans = 0;
	while(T--)
	{
		string s;
		cin >> s;

		int stk[10001][2] = {};
		int sCnt = 0;
		bool find = true;
		stk[0][0] = s[0];
		stk[0][1] = 1;
		for(int i=1; s[i]; i++)
		{
			if(stk[sCnt][0] == s[i])
				stk[sCnt][1] = (stk[sCnt][1] + 1) % 2;
			else
			{
				if(stk[sCnt][1] == 0)
				{
					if(sCnt)
					{
						sCnt--;
						i--;
					}
				}
				else
				{
					sCnt++;
					stk[sCnt][0] = s[i];
					stk[sCnt][1] = 1;
				}
			}
		}

		//cout << sCnt << endl;
		if(!sCnt && stk[sCnt][1] == 0)
			ans++;
	}

	cout << ans;
	return 0;
}