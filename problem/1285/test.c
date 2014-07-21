char coin[21][21];
int N,M;
updown(i,p)
{
  int j;
  if(p==0)for(j=0;j<N;j++)
  {
    coin[j][i]=!coin[j][i];
    
  }
  else for(j=0;j<N;j++)
  {
    coin[i][j]=!coin[i][j];
  }
}
count(i,p)
{
  int j,m=0;
  if(p==0)for(j=0;j<N;j++)
  {
    m+=!coin[j][i];
  }
  else for(j=0;j<N;j++)
  {
    m+=!coin[i][j];
  }
  return m;
}
f(i)
{
  if(i<N)
  {
    int m;
    f(i+1);
    updown(i,0);
    m=count(i,0);
    if(m<=N/2)f(i+1);
    updown(i,1);
    f(i+1);
    updown(i,0);
    m=count(i,1);
    if(m<=N/2)f(i+1);
  }
  else
  {
    int j,m;
    for(m=i=0;i<N;i++)for(j=0;j<N;j++)m+=!coin[i][j];
    M=m<M?m:M;
  }
}
main(i,j)
{
  i=0;for(scanf("%d ",&N);i<N;gets(coin+i++));
  for(i=0;i<N;i++)for(j=0;j<N;j++)coin[i][j]=coin[i][j]=='H';
  M=N*N;f(0);
  printf("%d",M);
}
