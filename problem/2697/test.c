#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char a[81],b[81];
int len;

int cmp(char *p, char *q)
{
	return *q-*p;
}

int cmp2(char *p, char *q)
{
	return *p-*q;
}

void swap(char *p, char *q)
{
	char t = *p;
	*p = *q;
	*q = t;
}

int getNext(int pos)
{
	char tok = a[pos];

	for(char i = tok+1; i <= '9'; i++)
	{
		for(int j=pos+1;j<len;j++)
		{
			if(a[j] == i)
				return j;
		}
	}
	return -1;
}

int main()
{
	int T;
	scanf("%d ",&T);
	for(;T--;)
	{
		len = strlen(gets(a));
		strcpy(b,a);

		qsort(b,len,1,cmp);
		if(strcmp(a,b)==0)
		{
			puts("BIGGEST");
			continue;
		}

		for(int i=len-1;i>=0;i--)
		{
			int next = getNext(i);
			if(next == -1)
				continue;
			swap(&a[i],&a[next]);
			qsort(a+i+1,len-i-1,1,cmp2);
			break;
		}
		puts(a);
	}
	return 0;
}