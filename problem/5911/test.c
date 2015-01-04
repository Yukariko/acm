int N,B;
int P[1001],S[1001],dp[2][1001][1001];
int max;
f(pos,money,chance,res)
{
  max = max < res? res: max;
  if(pos == N)return;
  if(money == 0) return;
  if(dp[chance][pos][res] > money)return;
  dp[chance][pos][res] = money;
  
  
  int bill = P[pos] + S[pos];
  f(pos+1,money,chance,res);
  if(money >= bill)
  {
    f(pos+1,money-bill,chance,res+1);
  }
  bill = P[pos] / 2 + S[pos];
  if(chance && money >= bill)
  {
    f(pos+1,money-bill,0,res+1);
  }
}

main()
{
  int i,j,k;
  scanf("%d%d",&N,&B);
  for(i=0;i<N;i++)
  {
    scanf("%d%d",&P[i],&S[i]);
  }
  f(0,B,1,0);
  printf("%d",max);
}
