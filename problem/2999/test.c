#include <stdio.h>
#include <string.h>

int main()
{
	char a[101];
	int len = strlen(gets(a));

	int R,C;
	for(int i=1;i*i<=len;i++)
	{
		if(len % i == 0)
		{
			R = i;
			C = len / i;
		}
	}

	for(int i=0;i<R;i++)
	{
		for(int j=0;j<C;j++)
		{
			putchar(a[i+j*R]);
		}
	}

	return 0;
}