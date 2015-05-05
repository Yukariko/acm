const char *keyBoard = "1234567890-=QWERTYUIOP[]ASDFGHJKL;'ZXCVBNM,./";

int main()
{
	char a[256];
	
	while(gets(a))
	{
		for(int i=0;a[i];i++)
		{
			if(a[i] == ' ')
			{
				putchar(' ');
				continue;
			}
			for(int j=0;keyBoard[j+1];j++)
				if(keyBoard[j+1] == a[i])
					putchar(keyBoard[j]);
		}
		puts("");
	}
	return 0;	
}
