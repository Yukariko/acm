#include <bits/stdc++.h>

using namespace std;

int main()
{
	char a[11] = {}, b[11] = {};
	scanf("%s%s", a, b);

	int alen = strlen(a);
	int blen = strlen(b);

	reverse(a, a + alen);
	reverse(b, b + blen);

	bool find = false;
	bool leading = true;
	for(int i=max(alen, blen) - 1; i >= 0; i--)
		if(a[i] >= b[i])
		{
			find = true;
			if(leading && a[i] == '0')
				continue;
			leading = false;
			putchar(a[i]);
		}
	if(!find)
		puts("YODA");
	else if(leading)
		puts("0");
	else
		puts("");

	find = false;
	leading = true;
	for(int i=max(alen, blen) - 1; i >= 0; i--)
		if(a[i] <= b[i])
		{
			find = true;
			if(leading && b[i] == '0')
				continue;
			leading = false;
			putchar(b[i]);
		}
	if(!find)
		puts("YODA");
	else if(leading)
		puts("0");
	else
		puts("");

	return 0;
}