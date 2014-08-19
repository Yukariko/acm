main()
{
  int n;
  scanf("%d",&n);
  int i,j,s=0;
  for(i=1;i<=n;i++)
  {
    for(j=i;i*j<=n;j++)s++;
  }
  printf("%d",s);
}
