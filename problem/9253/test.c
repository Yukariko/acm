main()
{
	char a[200001];
	char b[200001];
	char c[200001];
	gets(a);
	gets(b);
	gets(c);
	puts(strstr(a,c) && strstr(b,c)? "YES":"NO");
}
