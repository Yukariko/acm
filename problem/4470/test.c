int n;
char a[51];
main()
{
  int i;
  n=atoi(gets(a));
  for(i=1;i<=n;i++)
  {
    gets(a);
    printf("%d. %s\n",i,a);
  }
}
