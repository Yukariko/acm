main()
{
  int t;
  for(scanf("%d",&t);t--;)
  {
    int n,a;
    scanf("%d%d",&n,&a);
    int time[101];
    int dist[101][101];
    int visit[101]={0};
    int i,j,t=0,k;
    for(i=1;i<n;scanf("%d",time+i++));
    for(i=1;i<=n-1;i++)
    {
      int s=time[i];
      dist[i][i]=987654321;
      for(j=i+1;j<=n-1;j++)
      {
        dist[i][j]=s;
        dist[j][i]=s;
        s+=time[j];
      }
    }
    visit[a]=1;
    for(k=0;k<n-1;k++)
    {
      int min=a;
      for(i=1;i<n;i++)
      {
        if(visit[i]==0)min=dist[a][min]>dist[a][i]?i:min;
      }
      if(visit[min]==0)
      {
        visit[min]=1;
        t+=dist[a][min];
        a=min;
      }
    }
    printf("%d\n",t);
  }
}
