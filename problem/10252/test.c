print(m,n)
{
  printf("(%d,%d)\n",m,n);
}
main()
{
  int t;
  for(scanf("%d",&t);t--;)
  {
    int m,n;
    int i,j;
    scanf("%d%d",&m,&n);
    puts("1");
    if(m%2)
    {
      print(0,0);
      for(i=0;i<m;i++)print(i,n-1);
      for(i=m-1;i>=0;i--)
      {
        if(i%2==0)
        {
          int end = i==0;
          for(j=n-2;j>=end;j--)print(i,j);
        }
        else
        {
          for(j=0;j<n-1;j++)print(i,j);
        }
      }
    }
    else 
    {
      for(i=0;i<n;i++)print(0,i);
      for(i=1;i<m;i++)print(i,n-1);
      for(i=m-1;i>=1;i--)
      {
        if(i%2)
        {
          for(j=n-2;j>=0;j--)print(i,j);
        }
        else
        {
          for(j=0;j<n-1;j++)print(i,j);
        }
      }
    }
  }
}
