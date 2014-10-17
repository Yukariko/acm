int N;
int map[17][17];
int visit,start;
int min;
int dp[16][1<<16];
f(int pos,int score,int count)
{
  if(count==N)
  {
    if(map[pos][start]==0)return;
    score+=map[pos][start];
    min=min>score?score:min;
    return;
  }
  if(score>=min)return;
  if(dp[pos][visit]&&dp[pos][visit]<=score)return;
  dp[pos][visit]=score;
  for(int i=0;i<N;i++)
  {
    if((visit&(1<<i))==0&&map[pos][i])
    {
      visit|=1<<i;
      f(i,score+map[pos][i],count+1);
      visit^=1<<i;
    }
  }
}

main()
{
  int i,j;
  scanf("%d",&N);
  for(i=0;i<N;i++)
  {
    for(j=0;j<N;j++)
    {
      scanf("%d",&map[i][j]);
    }
  } 
  min=987654321;
  for(start=0;start<N;start++)
  {
    visit=0;
    visit|=1<<start;
    f(start,0,1);
    visit^=1<<start;
  }
  printf("%d",min);
}
