#include <stdio.h>
#include <string.h>

int main()
{
	char a[81];
	int line = 0;
	for(;~scanf("%s",a);)
	{
		if(strncmp(a,"<br>",4) == 0)
		{
			puts("");
			line = 0;
			continue;
		}
		if(strncmp(a,"<hr>",4) == 0)
		{
			if(line)
				puts("");
			for(int i=0;i<80;i++)
				putchar('-');
			puts("");
			line = 0;
			continue;
		}
		int len = strlen(a);
		if(line + len >= 80)
		{
			puts("");
			line = 0;
		}
		line += len+1;
		printf("%s ",a);
	}
	return 0;	
}
