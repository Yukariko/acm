int network[1001][1001];
int mask[1001];
int N,M,c=987654321;
int i;
f(x,s)
{
  int i,p=0,k;
  for(i=1;i<=N;i++)
  {
    k=network[i][x];
    if(k)
    {
      network[i][x]=network[x][i]=0;
      mask[i]=1;
      f(i,s+network[i][x]);
      mask[i]=0;
      network[i][x]=network[x][i]=k;
    }
    if(mask[i])
    {
      p++;
    }
  }
  if(p==N)c=s<c?s:c;
}
main(x,y,m)
{
  for(scanf("%d%d",&N,&M);i<M;i++){scanf("%d%d%d",&x,&y,&m);network[x][y]=m;network[y][x]=m;}
  mask[1]=1;f(1);
  printf("%d",c);
}
