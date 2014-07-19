int sum_seq[1001][1001];
int seq[1001];
int N;
int i,j,k,s;
main()
{
  for(scanf("%d",&N);i<N;i++)
  {
    for(j=0;j<N;j++)scanf("%d",&sum_seq[i][j]);
  }
  k=sum_seq[0][1];
  for(i=2;i<N;i++)
  {
    for(s=j=0;j<i;j++)
    {
      s+=sum_seq[j][i];
    }
    seq[i]=(s-k)/i;
    k+=seq[i];
  }
  if(N>2)
  {
    seq[0]=sum_seq[0][2]-seq[2];
    seq[1]=sum_seq[1][2]-seq[2];
  }
  else
  {
    seq[0]=1;
    seq[1]=sum_seq[0][1]-1;
  }
  for(i=0;i<N;i++)printf("%d ",seq[i]);
}
