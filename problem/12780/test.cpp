#include <bits/stdc++.h>

using namespace std;

char a[100001];
char b[11];

int main()
{
	gets(a);
	int len = strlen(gets(b));

	int ans = 0;
	for(int i=0; a[i]; i++)
		ans += strncmp(a + i, b, len) == 0;

	printf("%d", ans);
	return 0;
}