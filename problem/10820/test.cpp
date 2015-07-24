#include <iostream>
#include <cstdio>
#include <cstdlib>

using namespace std;

int main()
{
	char a[101];
	while(gets(a))
	{
		int ans[4] = {};

		for(int i=0; a[i]; i++)
		{
			if(isalpha(a[i]))
			{
				if(a[i] >= 'a')
					ans[0]++;
				else
					ans[1]++;
			}
			else if(isdigit(a[i]))
				ans[2]++;
			else
				ans[3]++;
		}

		for(int i=0; i < 4; i++)
			cout << ans[i] << " ";
		cout << endl;
	}
}