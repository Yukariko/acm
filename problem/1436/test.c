main()
{
  int n;
  scanf("%d",&n);
  int i,j;
  for(i=666;n;i++)
  {
    for(j=i;j&&j%1000!=666;j/=10);
    if(j)n--;
  }
  printf("%d",i-1);
}
