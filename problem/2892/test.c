main()
{
  int n;
  char a[4];
  for(scanf("%d",&n);n--;)
  {
    scanf(" %s",a);
    putchar(a[0]>='4'?'-':'.');
  }
}
