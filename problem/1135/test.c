#define MAX(a,b) (a>b?a:b)
int count[51];
int tree[51][51];
int n;
f(i)
{
  int p,q,r=0;
  if(count[i]==0)return 0;
  int dp[51]={};
  for(p=0;p<n;p++)
  {
    if(tree[i][p]==1)
    {
      q=f(p)+1;
      dp[q]+=1;
      if(count[i]<q)
      {
        count[i]=q;
      }
    }
  }
  for(p=n;p;p--)
  {
    if(dp[p])
    {
      count[i]=MAX(count[i],p+r);
      dp[p]--;
      p++;
      r++;
    }
  }
  return count[i];
}
main()
{
  int i,j,k=0;
  scanf("%d",&n);scanf("%d",&j);
  for(i=1;i<n;i++)
  {
    scanf("%d",&j);
    tree[j][i]=1;
    count[j]++;
  }
  f(0);
  printf("%d",count[0]);
}
