int F,S,G,U,D;
int dp[1000001];
int min=987654321;
f(pos,count)
{
  if(pos>F || pos<1)return;
  if(pos == G)
  {
    min=min>count?count:min;
    return;
  }
  if(dp[pos] && dp[pos] <= count) return;
  dp[pos] = count;
  f(pos+U,count+1);
  f(pos-D,count+1);
}
main()
{
  scanf("%d%d%d%d%d",&F,&S,&G,&U,&D);
  f(S,0);
  if(min==987654321)
  {
    return puts("use the stairs"),0;
  }
  printf("%d",min);
}
