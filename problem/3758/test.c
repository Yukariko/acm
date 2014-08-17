main()
{
  int t;
  for(scanf("%d",&t);t--;)
  {
    int n,k,t,m;
    int count[101]={0};
    int time[101];
    int score[101][101]={0};
    int curTime=0;
    int i,j,s;
    for(scanf("%d%d%d%d",&n,&k,&t,&m);curTime++<m;)
    {
      scanf("%d%d%d",&i,&j,&s);
      score[i][0]-=score[i][j];
      score[i][j]=score[i][j]<s?s:score[i][j];
      score[i][0]+=score[i][j];
      time[i]=curTime;
      count[i]++;
    }
    int rank=0;
    for(i=1;i<=n;i++)
    {
      if(score[t][0] < score[i][0])rank++;
      else if(score[t][0]==score[i][0])
      {
        if(count[t] > count[i])rank++;
        else if(count[t] == count[i])
        {
          if(time[t] > time[i])rank++;
          else if(time[t] == time[i])rank++;
        }
      }
    }
    printf("%d\n",rank);
  }
}
