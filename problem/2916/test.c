int a[361];
int visit[361];
int n,k;
f(s)
{
  int i,t;
  for(i=0;i<n;i++)
  {
    t=(s+a[i])%360;
    if(visit[t]==0)
    {
      a[n++]=t;
      visit[t]=1;
      f(t);
    }
  }
}
main()
{
  scanf("%d%d",&n,&k);
  int i,t;
  for(i=0;i<n;i++)scanf("%d",a+i);
  f(0);
  for(i=0;i<k;i++){scanf("%d",&t);puts(visit[t]?"YES":"NO");}
}

