#include <bits/stdc++.h>

using namespace std;

int main()
{
	char a[101];

	while(gets(a), a[0] != '.')
	{
		stack<pair<bool, int>> check;

		bool balanced = true;
		for(int i=0; a[i]; i++)
		{
			if(a[i] == '(')
			{
				if(check.empty() || check.top().first == true)
					check.push({false, 1});
				else
					check.top().second++;
			}

			else if(a[i] == '[')
			{
				if(check.empty() || check.top().first == false)
					check.push({true, 1});
				else
					check.top().second++;
			}

			else if(a[i] == ')')
			{
				if(check.empty() || check.top().first == true)
				{
					balanced = false;
					break;
				}
				else
				{
					check.top().second--;
					if(check.top().second == 0)
						check.pop();
				}
			}

			else if(a[i] == ']')
			{
				if(check.empty() || check.top().first == false)
				{
					balanced = false;
					break;
				}
				else
				{
					check.top().second--;
					if(check.top().second == 0)
						check.pop();
				}
			}
		}

		if(!check.empty())
			balanced = false;

		puts(balanced? "yes": "no");
	}
	return 0;
}