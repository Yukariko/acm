#include <bits/stdc++.h>

using namespace std;

const char *trash[] = {"i", "pa", "te", "ni", "niti", "a", "ali", "nego", "no", "ili"};

int main()
{
	char a[101];
	gets(a);

	char *tok = strtok(a, " ");
	putchar(*tok - 32);
	while(tok = strtok(NULL, " "))
	{
		bool find = false;
		for(int i=0; i < 10; i++)
			if(strcmp(tok, trash[i]) == 0)
				find = true;
		if(!find)
			putchar(*tok - 32);
	} 
	return 0;
}