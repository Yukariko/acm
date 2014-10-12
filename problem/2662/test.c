int myMoney,numCompany;
int invest[301][21],dp[301][21];
int curInvest[21],resInvest[21];
int max;
f(resMoney,nCompany,curMoney)
{
  int i;
  if(nCompany>numCompany)
  {
    if(max<resMoney)
    {
      max=resMoney;
      for(i=1;i<=numCompany;i++)resInvest[i]=curInvest[i];
    }
    return;
  }
  if(dp[curMoney][nCompany]>=resMoney)return;
  dp[curMoney][nCompany]=resMoney;
  
  for(i=0;i<=curMoney;i++)
  {
    curInvest[nCompany]=i;
    f(resMoney+invest[i][nCompany],nCompany+1,curMoney-i);
  }
}

main()
{
  int i,j,k;
  int money;
  scanf("%d%d",&myMoney,&numCompany);
  for(i=1;i<=myMoney;i++)
  {
    scanf("%d",&money);
    for(j=1;j<=numCompany;j++)
    {
      scanf("%d",&invest[money][j]);
      dp[i][j]=-1;
    }
  }
  f(0,1,myMoney);
  printf("%d\n",max);
  for(i=1;i<=numCompany;i++)printf("%d ",resInvest[i]);
}
