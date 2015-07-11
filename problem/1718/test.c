#include <stdio.h>

int main()
{
	char a[30001];
	char b[30001];
	gets(a);
	gets(b);

	for(int i=0; a[i]; )
	{
		for(int j=0; b[j] && a[i]; j++, i++)
		{
			if(a[i] == ' ')
			{
				putchar(' ');
				continue;
			}
			putchar(((a[i] - 'a') - (b[j] - 'a') + 25) % 26 + 'a');
		}
	}

	return 0;
}