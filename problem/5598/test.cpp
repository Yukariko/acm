#include <bits/stdc++.h>

using namespace std;

int main()
{
	char a[1001];
	gets(a);
	for(int i=0; a[i]; i++)
		putchar((a[i] - 'A' + 23) % 26 + 'A');
	return 0;
}