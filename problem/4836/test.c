#include <stdio.h>
#include <string.h>
#include <stdlib.h>

const char *dance[] = { 
	"jiggle", "dip", "twirl", "hop", "clap", "stomp","DIP"
};

enum {JIGGLE,DIP,TWIRL,HOP,CLAP,STOMP,BIGDIP,ELSE};

int main()
{
	char a[100001];
	for(;gets(a);)
	{
		char b[100001];
		int err[6];
		int errNum = 0;

		int len = strlen(a);

		int tok[1001];
		int ntok = 0;
		int find;

		strcpy(b,a);
		char *t = strtok(b," ");

		do
		{
			find = 0;
			for(int i=0; i < 6; i++)
				if(strcmp(t, dance[i]) == 0)
				{
					tok[ntok++] = i;
					find = 1;
					break;
				}
			if(!find)
				tok[ntok++] = ELSE;
		} while(t = strtok(NULL," "));

		// 1
		find = 0;
		for(int i=0; i < ntok; i++)
		{
			if(tok[i] == DIP)
			{
				if(i && tok[i-1] == JIGGLE)
					continue;
				if(i > 1 && tok[i-2] == JIGGLE)
					continue;
				if(i + 1 != ntok && tok[i+1] == TWIRL)
					continue;
				find = 1;
				tok[i] = BIGDIP;
			}
		}
		if(find)
			err[errNum++] = 1;

		// 2
		if(ntok < 3 || !(tok[ntok-3] == CLAP && tok[ntok-2] == STOMP && tok[ntok-1] == CLAP))
			err[errNum++] = 2;

		// 3
		for(int i=0; i < ntok; i++)
		{
			if(tok[i] == TWIRL && (i+1 == ntok || tok[i+1] != HOP))
			{
				err[errNum++] = 3;
				break;
			}
		}

		// 4
		if(tok[0] == JIGGLE)
			err[errNum++] = 4;

		// 5
		find = 0;
		for(int i=0; i < ntok; i++)
		{
			if(tok[i] == DIP || tok[i] == BIGDIP)
			{
				find = 1;
				break;
			}
		}
		if(!find)
			err[errNum++] = 5;

		if(!errNum)
			printf("form ok: %s\n",a);
		else
		{
			printf("form %s ",errNum > 1? "errors":"error");
			for(int i=0; errNum--; i++)
			{
				printf("%d", err[i]);
				if(errNum > 1)
					printf(", ");
				else if(errNum == 1)
					printf(" and ");
			}
			printf(": ");
			t = strtok(a," ");
			int i=0;
			do
			{
				if(tok[i] == ELSE)
					printf("%s ",t);
				else
					printf("%s ",dance[tok[i]]);
				i++;
			} while(t = strtok(NULL, " "));
			puts("");
		}
	}
	return 0;
}