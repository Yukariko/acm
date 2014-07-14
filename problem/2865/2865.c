int i,j;
float score,s,val[101][101],rank[101];
int max,part;
main(n,m,k)
{
  for(scanf("%d%d%d",&n,&m,&k);j<m;j++)
  {
    for(i=0;i<n;i++)
    {
      scanf("%d%f",&part,&score);
      val[part-1][j]=score;
    }
  }
  for(i=0;i<n;i++)
  {
    for(max=j=0;j<m;j++)
    {
      max=val[i][max]<val[i][j]?j:max;
    }
    rank[i]=val[i][max];
  }
  for(i=0;i<k;i++)
  {
    for(max=j=0;j<n;j++)
    {
      max=rank[max]<rank[j]?j:max;
    }
    s+=rank[max];
    rank[max]=0.0;
  }
  printf("%.1f",s);
}
