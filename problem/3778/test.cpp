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
	cin.ignore(1);
	for(int tc=1; tc <= T; tc++)
	{
		string a, b;
		getline(cin, a);
		getline(cin, b);

		int c[26] = {};
		for(int i=0; a[i]; i++)
			c[a[i]-'a']++;
		for(int i=0; b[i]; i++)
			c[b[i]-'a']--;

		int ans = 0;
		for(int i=0; i < 26; i++)
			ans += abs(c[i]);
		cout << "Case #" << tc << ": " << ans << '\n';
	}

	return 0;
}