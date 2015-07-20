#include <iostream>
#include <algorithm>

using namespace std;

int main()
{
	string a;
	cin >> a;

	int stk = 0;
	int ans = 0;

	for(int i=0; a[i]; i++)
	{
		if(a[i] == '(')
		{
			if(a[i+1]==')')
			{
				ans += stk;
				i++;
			}
			else
				stk++;
		}
		else
		{
			ans++;
			stk--;
		}
	}

	cout << ans;
	return 0;
}