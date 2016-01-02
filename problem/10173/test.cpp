#include <bits/stdc++.h>

using namespace std;

int main()
{
	char a[81];
	while(gets(a), strcmp(a, "EOI"))
	{
		for(int i=0; a[i]; i++)
			if(isalpha(a[i]))
				a[i] |= 32;

		puts(strstr(a, "nemo")? "Found": "Missing");
	}
	return 0;
}