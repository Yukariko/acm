main()
{
  int n;
  for(;scanf("%d",&n),n;)
  {
    int s;
    for(;n>=10;n=s)
    {
      printf("%d ",n);
      for(s=1;n;n/=10)s*=n%10;
    }
    printf("%d\n",n);
  }
}
