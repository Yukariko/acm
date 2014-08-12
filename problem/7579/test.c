int m[101],c[101];
long long dp[10001];
int mask[10001][101];
int N,M;
#define max(a,b) a<b?b:a
#define min(a,b) a<b?a:b
main()
{
  int i,j,k,p;
  scanf("%d%d",&N,&M);
  for(i=0;i<N;scanf("%d",m+i++));
  for(i=0;i<N;scanf("%d",c+i++));
  for(i=0;i<N;i++)
  {
    if(dp[c[i]]<m[i])
    {
      dp[c[i]]=m[i];
      for(j=0;j<N;j++)mask[c[i]][j]=0;
      mask[c[i]][i]=1;
    }
  }
  for(p=0;p<N;p++)
  for(i=0;i<N;i++)
  {
    for(j=0;j+c[i]<10001;j++)
    {
      if(dp[j]&&mask[j][i]==0&&mask[j+c[i]][i]==0)
      {
        if(dp[j+c[i]]<dp[j]+m[i])
        {
          dp[j+c[i]]=dp[j]+m[i];
          for(k=0;k<N;k++)mask[j+c[i]][k]=mask[j][k];
          mask[j+c[i]][i]=1;
        }
      }
    }
  }
  for(i=0;i<N*N;i++)
  {
    if(dp[i] >= M)break;
  }
  for(j=0;j<N;j++)
  {
  //  if(mask[i][j])printf("%d\n",j);
  }
  printf("%d",i);
}
