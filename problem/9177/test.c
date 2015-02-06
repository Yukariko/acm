char a[201],b[201],s[401];
char dp[201][201];
int solve(int aPos,int bPos,int sPos)
{
  if(!s[sPos]) return 1;
  char *ret=&dp[aPos][bPos];
  if(*ret != -1) return *ret;
  *ret = 0;
  if(s[sPos] == a[aPos]) *ret |= solve(aPos+1,bPos,sPos+1);
  if(*ret == 1) return *ret;
  if(s[sPos] == b[bPos]) *ret |= solve(aPos,bPos+1,sPos+1);
  if(s[sPos] != a[aPos] && s[sPos] != b[bPos]) return 0;
  return *ret;
}
main()
{
  int N;
  scanf("%d",&N);
  for(int tc=1;tc<=N;tc++)
  {
    scanf(" %s%s%s",a,b,s);
    memset(dp,-1,sizeof(dp));
    printf("Data set %d: %s\n",tc,solve(0,0,0)?"yes":"no");
  }
}
