#define MIN(a,b) (a>b?b:a)
#define MAX(a,b) (a>b?a:b)
main()
{
  int n;
  int a[3];
  int min_dp[3],max_dp[3],t_dp[3];
  int i;
  scanf("%d",&n);
  scanf("%d%d%d",a,a+1,a+2);
  max_dp[0]=min_dp[0]=a[0];
  max_dp[1]=min_dp[1]=a[1];
  max_dp[2]=min_dp[2]=a[2];
  for(;--n;)
  {
    scanf("%d%d%d",a,a+1,a+2);
    t_dp[0]=a[0]+MIN(min_dp[0],min_dp[1]);
    t_dp[1]=a[1]+MIN(MIN(min_dp[0],min_dp[1]),min_dp[2]);
    t_dp[2]=a[2]+MIN(min_dp[1],min_dp[2]);
    for(i=0;i<3;i++)min_dp[i]=t_dp[i];
    t_dp[0]=a[0]+MAX(max_dp[0],max_dp[1]);
    t_dp[1]=a[1]+MAX(MAX(max_dp[0],max_dp[1]),max_dp[2]);
    t_dp[2]=a[2]+MAX(max_dp[1],max_dp[2]);
    for(i=0;i<3;i++)max_dp[i]=t_dp[i];
  }
  printf("%d %d",MAX(MAX(max_dp[0],max_dp[1]),max_dp[2]),\
  MIN(MIN(min_dp[0],min_dp[1]),min_dp[2]));
}
