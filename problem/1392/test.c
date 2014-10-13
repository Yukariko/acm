main()
{
  int n,m;
  int a[101];
  int i,j,k,s;
  scanf("%d%d",&n,&m);
  for(i=0;i<n;i++)
  {
    scanf("%d",a+i);
  }
  for(i=0;i<m;i++)
  {
    scanf("%d",&k);
    for(s=j=0;j<n;j++)
    {
      if(s+a[j]>k)break;
      s+=a[j];
    }
    printf("%d\n",j+1);
  }
}
