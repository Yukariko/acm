#include <bits/stdc++.h>

using namespace std;

const char *encode[] = {"c=", "c-", "dz=", "d-", "lj", "nj", "s=", "z="};

int main()
{
	string s;
	cin >> s;

	string cur;
	int ans = 0;
	for(int i=0; s[i]; i++)
	{
		cur = s[i];
		cur += s[i+1];

		bool find = false;
		for(int sel = 0; sel < 8; sel++)
		{
			if(cur == encode[sel])
			{
				find = true;
				ans++;
				break;
			}
		}

		if(cur == "dz" && s[i+2] == '=')
		{
			ans++;
			i+=2;
		}
		else if(find == false)
			ans++;
		else
			i++;
	}

	cout << ans;
	return 0;
}