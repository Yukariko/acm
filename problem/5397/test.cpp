#include <bits/stdc++.h>

using namespace std;

char a[1000001];

int main()
{
	int T;
	scanf("%d", &T);

	while(T--)
	{
		scanf("%s", a);

		list<char> ans;
		auto pointer = ans.begin();

		for(int i=0; a[i]; i++)
		{
			if(a[i] == '<')
			{
				if(pointer != ans.begin())
					pointer--;
			}
			else if(a[i] == '>')
			{
				if(pointer != ans.end())
					pointer++;
			}
			else if(a[i] == '-')
			{
				if(pointer != ans.begin())
				{
					pointer = ans.erase(--pointer);
				}
			}
			else
				ans.insert(pointer, a[i]);
		}

		for(auto pick : ans)
			putchar(pick);
		puts("");
	}
	return 0;
}