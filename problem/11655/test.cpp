#include <bits/stdc++.h>

using namespace std;

int main()
{
	char a[101];
	gets(a);

	for(int i=0; a[i]; i++)
		if(isalpha(a[i]))
			putchar(((a[i] | 32) - 'a' + 13) % 26 + (a[i] & 32) + 'A');
		else
			putchar(a[i]);

	return 0;
}