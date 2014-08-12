int n;
main()
{
  scanf("%d",&n);
  int i,j=0,s=0;
  int stack[121];
  for(i=1;(s+=i*(i+1)/2)<=n;i++)
  {
    stack[j++]=s;
  }
  int dp[300001];
  for(i=0;i<=n;i++)dp[i]=300001;
  for(i=0;i<j;i++)
  {
    int k;
    dp[stack[i]]=1;
    for(k=stack[i];k<=n;k++)
    {
      dp[k]=dp[k]>dp[k-stack[i]]+1?dp[k-stack[i]]+1:dp[k];
    }
  }
  printf("%d",dp[n]);
}
