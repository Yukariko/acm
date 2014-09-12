main()
{
  int n,m;
  scanf("%d%d",&n,&m);
  int i,max=m;
  for(i=0;i<n;i++)
  {
    int a,b;
    scanf("%d%d",&a,&b);
    m=m+a-b;
    if(m<0)return puts("0"),0;
    max=max<m?m:max;
  }
  printf("%d",max);
}
