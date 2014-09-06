main()
{
  int queue[102][2];
  int t;
  for(scanf("%d",&t);t--;)
  {
    int n,m;
    scanf("%d%d",&n,&m);
    int i;
    for(i=0;i<n;i++)
    {
      scanf("%d",&queue[i][0]);
      queue[i][1]=i;
    }
    int s=0;
    for(;;)
    {
      for(i=1;i<n;i++)
      {
        if(queue[0][0]<queue[i][0])break;
      }
      if(i!=n)
      {
        queue[n][0]=queue[0][0];
        queue[n][1]=queue[0][1];
      }
      else
      {
        s++;
        n--;
        if(queue[0][1]==m)break;
      }
      for(i=0;i<n;i++)
      {
        queue[i][0]=queue[i+1][0];
        queue[i][1]=queue[i+1][1];
      }
    }
    printf("%d\n",s);
  }
}
