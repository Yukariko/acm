main()
{
  int n,m,k;
  scanf("%d%d%d",&n,&m,&k);
  int pair=0;
  for(;n>=2&&m>=1;)
  {
    n-=2;
    m-=1;
    pair++;
  }
  k-=n+m;
  for(;k>0;k-=3)pair--;
  printf("%d",pair);
}
