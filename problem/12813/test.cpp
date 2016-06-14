#include <bits/stdc++.h>

using namespace std;

char a[100001];
char b[100001];

int main()
{
	scanf("%s%s", a, b);
	for(int i=0; a[i]; i++)
		printf("%d", (a[i] - '0') & (b[i] - '0'));
	puts("");

	for(int i=0; a[i]; i++)
		printf("%d", (a[i] - '0') | (b[i] - '0'));
	puts("");
	for(int i=0; a[i]; i++)
		printf("%d", (a[i] - '0') ^ (b[i] - '0'));
	puts("");
	for(int i=0; a[i]; i++)
		printf("%d", !(a[i] - '0'));
	puts("");
	for(int i=0; a[i]; i++)
		printf("%d", !(b[i] - '0'));
	return 0;
}