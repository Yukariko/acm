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
      dist[i][n]=s;
      dist[n][i]=s;
    }
    dist[n][n]=987654321;
    visit[a]=1;
    for(j=k=0;k<n-1;k++)
    {
      int min=a;
      for(i=1;i<=n;i++)
      {
        if(visit[i]==0)
        {
          if(dist[a][min]>dist[a][i])
          {
            min=i;
          }
          else if (dist[a][min]==dist[a][i])
          {
            printf("! %d %d\n",min,i);
            //if(abs(a-min)<abs(a-i)){min=i;}
          }
        }
      }
      if(visit[min]==0)
      {
        visit[min]=1;
        j+=dist[a][min];
        t+=j;
        
        a=min;
      }
      printf("[%d] %d %d\n",a,t,j);
    }
    printf("%d\n",t);
  }
}
