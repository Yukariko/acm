main()
{
  int t,n;
  for(scanf("%d",&t);t--;)
  {
    scanf("%d",&n);
    printf("%d\n",(1<<n)-1);
  }
}
