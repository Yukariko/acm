#include <stdio.h>
#include <string.h>
#include <stdlib.h>

char a[1000001];
char b[37];
int jump[1000001];
int alen;
int blen;

void solve(int pos)
{
	if(pos < 0)
		return;

	int find = 0;
	int t = pos;
	for(int i=0; i < blen && pos < alen; i++,pos++)
	{
		for(;!a[pos];)
			pos += jump[pos];
		if(a[pos] == b[i])
			find++;
		else
			break;
	}
	if(find == blen)
	{
		a[t] = 0;
		jump[t] = pos-t;
	}
	solve(t-1);
}

int main()
{
	alen = strlen(gets(a));
	blen = strlen(gets(b));

	solve(alen-blen);
	int find=0;
	for(int i=0;i<alen;i++)
	{
		if(a[i])
		{
			find = 1;
			putchar(a[i]);
		}
		else
			i += jump[i]-1;
	}
	if(!find)
		puts("FRULA");
	return 0;
}
