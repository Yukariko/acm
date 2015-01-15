int H,C;
double S[201];
double dp[201][201];
double err[201][201];
#define LI(i,j,k) dabs((S[i] + (S[j] - S[i]) * (k - i) / (j - i)) - S[k])


double min(double a,double b){return a>b?b:a;}
double dabs(double a){return a>0?a:-a;}

#define INF 10000001.0


void getError()
{
  for(int i=0;i<H;i++)
  {
    for(int j=i+2;j<H;j++)
    {
      err[i][j] = 0.0;
      for(int k=i+1; k < j; k++)
      {
        err[i][j] += LI(i,j,k);
      }
    }
  }
}

double solve(int pos, int count)
{
  if(count < 2 || dp[pos][count] < INF) return dp[pos][count];
  for(int i=0;i<pos;i++)
  {
    dp[pos][count] = min(dp[pos][count], solve(i, count-1) + err[i][pos]);
  }
  return dp[pos][count];
}

main()
{
  int T;
  scanf("%d",&T);  
  for(;T--;)
  {
    scanf("%d%d",&H,&C);
    for(int i=0;i<H;i++)scanf("%lf",&S[i]);
    for(int i=0;i<H;i++)
      for(int j=0;j<H;j++)
        dp[i][j] = i? INF : 0;
    getError();
    printf("%.4lf\n",solve(H-1, C) / H);
  }
}
