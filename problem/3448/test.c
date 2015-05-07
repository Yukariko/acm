#include <stdio.h>
#include <string.h>

int main()
{
	int T;
	for(scanf("%d ",&T);T--;)
	{
		char a[101];
		int len = 0;
		int err = 0;

		while(gets(a) && a[0])
		{
			for(int i=0;a[i];i++)
			{
				if(a[i] == '#')
					err++;
				len++;
			}
		}
		int res = (len-err) * 10000 / len;
		if(res % 100 && (res % 100) + 5 < 100)
			printf("Efficiency ratio is %d.%d%%.\n",res/100,(res+5)/10%10);
		else
			printf("Efficiency ratio is %d%%.\n",(res+5) / 100);
	}
}