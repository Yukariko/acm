main()
{
  int n;
  long long i;
  int j;
  for(;~scanf("%d",&n);)
  {
    for(j=i=1;;j++)
    {
      if(i%n==0)break;
      i=(i*10)%n+1;
    }
    printf("%d\n",j);
  }
}
