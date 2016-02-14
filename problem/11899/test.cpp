#include <bits/stdc++.h>

using namespace std;

int main()
{
	char a[51];
	gets(a);

	int ans = 0;
	int left = 0;
	for(int i=0; a[i]; i++)
	{
		if(a[i] == '(')
			left++;
		else
			left--;
		if(left < 0)
		{
			ans++;
			left = 0;
		}
	}

	ans += left;
	printf("%d", ans);
	return 0;
}