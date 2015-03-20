const char *SEG[10] = {"063","010","093","079","106","103","119","011","127","107"};

main()
{
	char a[128];
	for(;gets(a),*a != 'B';)
	{
		int p=0,q=0;
		int i;
		for(i=0;a[i]!='+';i+=3)
		{
			p *= 10;
			for(int j=0;j<10;j++)
			{
				if(strncmp(a+i,SEG[j],3) == 0)
				{
					p += j;
					break;
				}
			}
		}
		for(++i;a[i]!='=';i+=3)
		{
			q *= 10;
			for(int j=0;j<10;j++)
			{
				if(strncmp(a+i,SEG[j],3) == 0)
				{
					q += j;
					break;
				}
			}
		}
		int ret = p + q;
		printf("%s",a);
		for(i=1000000000;i;i/=10)
			if(ret / i)
				printf("%s",SEG[ret/i%10]);
		puts("");
	}
}