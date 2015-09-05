#include <iostream>
#include <algorithm>
#include <cstring>
#include <vector>
#include <cstdio>
#include <map>

using namespace std;

int main()
{
	string s;
	cin >> s;
	int T;
	cin >> T;

	vector<string> ans;

	while(T--)
	{
		string a;
		cin >> a;

		bool find = true;
		for(int i=0; a[i]; i++)
			if(s[i] != '*' && s[i] != a[i])
				find = false;
		if(find)
			ans.push_back(a);
	}

	cout << ans.size() << '\n';
	for(int i=0; i < ans.size(); i++)
		cout << ans[i] << '\n';
	return 0;
}