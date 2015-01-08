int T,K;
int price[101];
int count[101];
int dp[10001][101];
f(money,pos)
{
  
  int result=0;
  if(money == 0)return 1;
  if(pos == K)return 0;
  if(dp[money][pos])return dp[money][pos];
  for(int i=0;i <= count[pos];i++)
  {
    int cur_price = i * price[pos];
    if(cur_price <= money)
    {
      result+=f(money - cur_price,pos+1);
    }
    else break;
  }
  return dp[money][pos]=result;
}
main()
{
  scanf("%d%d",&T,&K);
  for(int i=0;i<K;i++)
  {
    scanf("%d%d",&price[i],&count[i]);
  }
  printf("%d",f(T,0));
}
