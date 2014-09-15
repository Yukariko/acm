char map[16][16];
int count;
int N;
char col[16];
check(p,q)
{
  int i,j;
  for(i=p-1,j=q-1;i>=0&&j>=0;i--,j--)if(map[i][j])return 0;
  for(i=p-1,j=q+1;i>=0&&j<N;i--,j++)if(map[i][j])return 0;
  for(i=p+1,j=q-1;i<N&&j>=0;i++,j--)if(map[i][j])return 0;
  for(i=p+1,j=q+1;i<N&&j<N;i++,j++)if(map[i][j])return 0;
  return 1;
}
f(n,p)
{
  if(n==0)
  {
    count++;
    return;
  }
  int i;
  for(i=0;i<N;i++)
  {
    if(!col[i]&&check(p,i))
    {
      col[i]=1;
      map[p][i]=1;
      f(n-1,p+1);
      map[p][i]=0;
      col[i]=0;
    }
  }
}
int solve[]={0,1,0,0,2,10,4,40,92,352,724,2680,14200,73712,365596};
main()
{
  scanf("%d",&N);
  f(N,0);
  printf("%d",count);
}