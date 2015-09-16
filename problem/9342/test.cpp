#include <iostream>
#include <algorithm>
#include <cstring>
#include <vector>
#include <cstdio>
#include <map>

using namespace std;

int main()
{
	int T;
	cin >> T;

	while(T--)
	{
		string s;
		cin >> s;

		const char *prefix = "ABCDEF";

		bool find = false;
		for(int i=0; prefix[i]; i++)
			if(s[0] == prefix[i])
				find = true;

		if(!find || s.size() < 3)
		{
			cout << "Good\n";
			continue;
		}

		find = false;
		for(int i=0; prefix[i]; i++)
			if(s[s.size() - 1] == prefix[i])
				find = true;
		if(!find)
		{
			cout << "Good\n";
			continue;
		}

		if(s[0] != 'A')
			s = s.substr(1);

		if(s[s.size() - 1] != 'C')
			s = s.substr(0, s.size() - 1);

		int level = 0;

		for(int i=1; s[i]; i++)
		{
			if(s[i] != s[i-1])
			{
				if(level == 0)
				{
					if(s[i-1] != 'A')
					{
						level = -1;
						break;
					}
					else
						level++;
				}
				else if(level == 1)
				{
					if(s[i-1] != 'F')
					{
						level = -1;
						break;
					}
					else
						level++;
				}
				else if(level == 2)
				{
					level = -1;
					break;
				}
			}
		}

		if(level != 2 || s[s.size() - 1] != 'C')
		{
			cout << "Good\n";
			continue;
		}
		cout << "Infected!\n";
	}
	return 0;
}