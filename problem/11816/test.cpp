#include <bits/stdc++.h>

using namespace std;

int main()
{
	char a[21];
	gets(a);
	if(a[0] == '0' && a[1] == 'x')
		printf("%lld", strtoll(a, NULL, 16));
	else if(a[0] == '0' && a[1])
		printf("%lld", strtoll(a, NULL, 8));
	else
		printf("%lld", strtoll(a, NULL, 10));
	return 0;
}