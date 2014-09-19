main()
{
  int t;
  for(scanf("%d",&t);t--;)
  {
    int b;
    scanf("%d ",&b);
    char c;
    int s=0;
    for(;c=getchar(),c!=10;)
    {
      s+=c-'0';
    }
    printf("%d\n",s%(b-1));
  }
}
