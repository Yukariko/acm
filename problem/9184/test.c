int dp[21][21][21];
w(a,b,c)
{
  if (a<=0||b<=0||c<=0)return 1;
  if (a>20||b>20||c>20)return w(20,20,20);
  if(dp[a][b][c])return dp[a][b][c];
  if (a<b&&b<c)return dp[a][b][c]=w(a,b,c-1)+w(a,b-1,c-1)-w(a,b-1,c);
  return dp[a][b][c]=w(a-1, b, c) + w(a-1, b-1, c) + w(a-1, b, c-1) - w(a-1, b-1, c-1);
}
main()
{
  int a,b,c;
  for(;scanf("%d%d%d",&a,&b,&c),a!=-1||b!=-1||c!=-1;)printf("w(%d, %d, %d) = %d\n",a,b,c,w(a,b,c));
}
