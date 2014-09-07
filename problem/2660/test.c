int n;
int friend[1001][1001];
int temp[1001];
f(p,k,s)
{
  int i;
  for(i=0;i<n;i++)
  {
    if(k!=i&&friend[p][i]&&friend[k][i]==0)
    {
      
    }
  }
}
main()
{
  scanf("%d",&n);
  int x,y;
  for(;scanf("%d%d",&x,&y),x!=-1;)
  {
    friend[x][y]=1;
    friend[y][x]=1;
  }
  int i;
  for(i=0;i<n;i++)
  {
    f(i,i,1);
  }
}
