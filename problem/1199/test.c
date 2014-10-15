int n;
int map[1001][1001];
int count[1001];
euler(pos)
{
  int i;
  for(i=0;i<n;i++)
  {
    for(;map[pos][i];)
    {
      map[pos][i]--;
      map[i][pos]--;
      euler(i);
    }
  }
  printf("%d ",pos+1);
}
 
main()
{
  int i,j;
  scanf("%d",&n);
  for(i=0;i<n;i++)
  {
    for(j=0;j<n;j++)
    {
      scanf("%d",&map[i][j]);
      count[i]+=map[i][j];
    }
    if(count[i] % 2)return puts("-1"),0;
  }
  euler(0);
}
