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

	int a[128] = {};
	for(int i=0; s[i]; i++)
		a[s[i]]++;

	cout << a['a'] + a['e'] + a['i'] + a['o'] + a['u'];
	return 0;
}