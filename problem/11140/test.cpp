#include <bits/stdc++.h>

using namespace std;

int main()
{
	int T;
	scanf("%d", &T);
	while(T--)
	{
		char a[53] = {};
		scanf("%s", a);

		int ans = 3;
		for(int i=0; a[i]; i++)
		{
			if(a[i] == 'l')
			{
				if(a[i+1] == 'o')
				{
					if(a[i+2] == 'l')
						ans = 0;
					else
						ans = min(ans, 1);
				}
				else if(a[i+1] == 'l')
					ans = min(ans, 1);
				else if(a[i+2] == 'l')
					ans = min(ans, 1);
				else
					ans = min(ans, 2);
			}
			else if(a[i] == 'o')
			{
				if(a[i+1] == 'l')
					ans = min(ans, 1);
				else
					ans = min(ans, 2);
			}
		}
		printf("%d\n", ans);
	}
	return 0;
}