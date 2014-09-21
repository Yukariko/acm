int a[1000001];
main()
{
  int n,m;
  scanf("%d%d",&n,&m);
  int i,j;
  for(i=0;i<n;i++)
  {
    scanf("%d",a+i);
  }
  int max=0,sel=0;
  for(i=m-1;i<n-m+1;i++)
  {
    if(sel<=i-m+1)
    {
      max=0;
      for(j=-m+1;j<=m-1;j++)
      {
        if(max<a[i+j])
        {
          max=a[i+j];
          sel=i+j;
        }
      }
    }
    else if(max<=a[i+m-1])
    {
      max=a[i+m-1];
      sel=i+m-1;
    }
    printf("%d ",max);
  }
}
