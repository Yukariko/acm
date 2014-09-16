main()
{
  int t;
  for(scanf("%d",&t);t--;)
  {
    int b;
    scanf("%d ",&b);
    char c;
    int s=0;
    for(;scanf("%c",&c),c!=10;)
    {
      s=s*b+c-'0';
      for(;s>=b-1;s-=b-1);
    }
    printf("%d\n",s);
  }
}
