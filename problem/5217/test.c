main()
{
  int t;
  for(scanf("%d",&t);t--;puts(""))
  {
    int n;
    scanf("%d",&n);
    printf("Pairs for %d:",n);
    int i;
    if(n<=2)continue;
    printf(" 1 %d",n-1);
    for(i=2;i<n-i;i++)
    {
      printf(", %d %d",i,n-i);
    }
  }
}
