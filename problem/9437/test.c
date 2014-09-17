main()
{
  int n,p;
  for(;scanf("%d%d",&n,&p),n;)
  {
    int i;
    for(i=1;;i+=2,n-=2)
    {
      if(i==p)
      {
        printf("%d %d %d",i+1,n-1,n);
        break;
      }
      if(i+1==p)
      {
        printf("%d %d %d",i,n-1,n);
        break;
      }
      if(n==p)
      {
        printf("%d %d %d",i,i+1,n-1);
        break;
      }
      if(n-1==p)
      {
        printf("%d %d %d",i,i+1,n);
        break;
      }
    }
    puts("");
  }
}
