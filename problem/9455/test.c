int box[101][101];
int n,m,i,j;s;
main(t)
{
  for(scanf("%d",&t);t--;printf("%d\n",s))
  {
    int state[101]={0};
    scanf("%d%d",&n,&m);
    for(i=s=0;i<n;i++)for(j=0;j<m;j++)scanf("%d",&box[i][j]);
    for(i=n-1;i>=0;i--)
    {
      for(j=0;j<m;j++)
      {
        if(box[i][j])
        {
          s+=n-i-1-state[j];
          state[j]++;
        }
      }
    }
  }
}
