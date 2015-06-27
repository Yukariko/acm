#include <stdio.h>
#include <string.h>
#include <stdlib.h>

void pop(char *a)
{
	for(int i=0;a[i];i++)
		a[i] = a[i+1];
}
void compress(char *a)
{
	for(;a[0]==' ';)
		pop(a);
	for(int i=0;a[i];i++)
	{
		if(isalpha(a[i]))
			a[i] |= 32;
		else if(a[i] == '[' || a[i] == '{')
			a[i] = '(';
		else if(a[i] == ']' || a[i] == '}')
			a[i] = ')';
		else if(a[i] == ';')
			a[i] = ',';
	}
	const char *tok = "().,: ";
	for(int i=0;a[i];i++)
	{
		if(a[i] == ' ')
		{
			int find = 0;
			for(int j=0; tok[j]; j++)
			{
				if(a[i+1] == tok[j] || a[i-1] == tok[j])
				{
					find = 1;
					break;
				}
			}
			if(find || a[i+1] == 0)
			{
				pop(a+i);
				i--;
			}
		}
	}
}

int main()
{
	int T;
	scanf("%d ",&T);
	for(int tc = 1; tc <= T; tc++)
	{
		char a[1002];
		char b[1002];
		compress(gets(a));
		compress(gets(b));
		printf("Data Set %d: %s\n",tc,strcmp(a,b)?"not equal":"equal");
		if(tc < T)
			puts("");
	}
	return 0;
}