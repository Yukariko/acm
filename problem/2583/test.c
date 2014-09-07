char map[101][101];
int m,n,k;
f(i,j)
{
  if(i<0||j<0||i>=m||j>=n||map[i][j])return 0;
  map[i][j]=1;
  return 1+f(i-1,j)+f(i+1,j)+f(i,j-1)+f(i,j+1);
}
cmp(int *a,int *b){return *a-*b;}
main()
{
  scanf("%d%d%d",&m,&n,&k);
  int x1,y1,x2,y2;
  for(;k--;)
  {
    scanf("%d%d%d%d",&x1,&y1,&x2,&y2);
    int t;
    for(;x1<x2;x1++)
    {
      for(t=y1;t<y2;t++)map[t][x1]=1;
    }
  }
  int i,j,k=0;
  int a[10001];
  for(i=0;i<m;i++)
  {
    for(j=0;j<n;j++)
    {
      if(map[i][j]==0)a[k++]=f(i,j);
    }
  }
  qsort(a,k,4,cmp);
  printf("%d\n",k);
  for(i=0;i<k;i++)printf("%d ",a[i]);  
}
