#include <bits/stdc++.h>

using namespace std;

const bool AND = true;
const bool OR = false;

char a[32001];

int stk[32001];

bool solve()
{
	stack<pair<bool, bool>> stk;

	int maxLevel = 0;
	int level = 0;
	for(int i=0; a[i]; i++)
	{
		if(a[i] == '(')
			level++;
		else if(a[i] == ')')
			level--;
		maxLevel = max(maxLevel, level);
	}

	if(maxLevel % 2)
		stk.push({false, OR});
	else
		stk.push({true, AND});

	for(int i=0; a[i]; i++)
	{
		if(a[i] == '(')
			stk.push({stk.top().second == OR? true: false, stk.top().second == OR? AND: OR});
		else if(a[i] == ')')
		{
			bool sel = stk.top().first;
			stk.pop();
			if(stk.top().second == OR)
				stk.top().first |= sel;
			else
				stk.top().first &= sel;
		}
		else
		{
			if(stk.top().second == OR)
				stk.top().first |= a[i] == 'T';
			else
				stk.top().first &= a[i] == 'T';
		}
	}
	return stk.top().first;
}

int main()
{
	for(int tc=1; gets(a), a[1] != ')'; tc++)
		printf("%d. %s\n", tc, solve()? "true": "false");
	return 0;
}