main()
{
  int n,k;
  scanf("%d%d",&n,&k);
  int i,j,s=0;
  char che[1001]={};
  for(i=2;i<=n;i++)
  {
    if(che[i]==0)
    {
      for(j=i;j<=n;j+=i)
      {
        if(che[j]==0)
        {
          che[j]=1;
          s++;
          if(s==k)return printf("%d",j),0;
        }
      }
    }
  }
}
