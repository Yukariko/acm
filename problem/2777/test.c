main()
{
  int t;
  int n;
  for(scanf("%d",&t);t--;)
  {
    scanf("%d",&n);
    int i,s=0;
    if(n==1){puts("1");continue;}
    for(;n>1;)
    {
      for(i=9;i>1;i--)
      {
        if(n%i==0)break;
      }
      if(i==1)break;
      n/=i;
      s++;
    }
    printf("%d\n",n>1?-1:s);
  }
}
