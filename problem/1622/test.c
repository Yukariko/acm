main()
{
	char a[1001],b[1001];
	for(;gets(a);)
	{
		gets(b);
		int ckA[26]={};
		int ckB[26]={};
		for(int i=0;a[i];i++)ckA[a[i]-'a']++;
		for(int i=0;b[i];i++)ckB[b[i]-'a']++;
		for(int i=0;i<26;i++)
		{
			int min = ckA[i] > ckB[i] ? ckB[i] : ckA[i];
			for(int j=0;j<min;j++)putchar(i+'a');
		}
		puts("");
	}
}
