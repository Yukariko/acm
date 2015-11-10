#include <bits/stdc++.h>

using namespace std;

int main()
{
	string s;
	while(getline(cin, s), s != "END")
	{
		reverse(s.begin(), s.end());
		cout << s << '\n';
	}
	return 0;
}