#include <iostream>
#include <cstdio>
#include <cstring>

using namespace std;

int main()
{
	int a[26];
	char s[101];
	cin >> s;

	memset(a,-1,sizeof(a));

	for(int i=0; s[i]; i++)
		if(a[s[i]-'a'] == -1)
			a[s[i]-'a'] = i;

	for(int i=0; i < 26; i++)
		cout << a[i] << " ";
	return 0;
}