#include <iostream>
#include <cstdio>
#include <cstring>

using namespace std;

int main()
{
	int a[26] = {};
	char s[101];
	cin >> s;

	for(int i=0; s[i]; i++)
		a[s[i]-'a']++;

	for(int i=0; i < 26; i++)
		cout << a[i] << " ";
	return 0;
}