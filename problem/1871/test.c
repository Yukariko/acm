main()
{
  int t,n,m;
  char plates[9];
  for(scanf("%d ",&t);t--;)
  {
    gets(plates);
    n=0;
    for(int i=4;plates[i];i++)
    {
      n=n*10+plates[i]-'0';
    }
    m=0;
    for(int i=0;i<3;i++)
    {
      m=m*26+plates[i]-'A';
    }
    puts(abs(n-m)<=100?"nice":"not nice");
  }
}
