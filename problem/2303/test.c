main()
{
  int n;
  scanf("%d",&n);
  int t;
  int a[5];
  int max=0;
  int res;
  for(t=1;t<=n;t++)
  {
    int i,j,k;
    int p;
    for(i=0;i<5;i++)scanf("%d",a+i);
    for(i=0;i<3;i++)
    {
      for(j=i+1;j<4;j++)
      {
        for(k=j+1;k<5;k++)
        {
          p=(a[i]+a[j]+a[k])%10;
          if(max<=p)
          {
            max=p;
            res=t;
          }
        }
      }
    }
  }
  printf("%d",res);
}
