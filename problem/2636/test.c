int map[101][101];
int n,m;
f(i,j)
{
  if(i<0||i>n-1||j<0||j>m-1)return;
  if(map[i][j]!=0)return;
  map[i][j]=2;
  f(i-1,j);f(i+1,j);f(i,j-1);f(i,j+1);
}
main()
{

  int temp[101][101];
  scanf("%d%d ",&n,&m);
  int i,j,k,s=0,c,cc;
  for(i=0;i<n;i++)
  {
    for(j=0;j<m;j++)
    {
      scanf("%d",&map[i][j]);
    }
  }
  c=cc=0;
  for(k=1;k;s++)
  {
    k=0;
    f(0,0);
    cc=0;
    for(i=0;i<n;i++)
    {
      for(j=0;j<m;j++)
      {
        if(map[i][j]==1)
        {
          int t=0;
          if(map[i-1][j]==2)t++;
          if(map[i+1][j]==2)t++;
          if(map[i][j-1]==2)t++;
          if(map[i][j+1]==2)t++;
          if(t>=1)temp[i][j]=0;
            else {temp[i][j]=1;cc++;}
          k=1;
        }
        else temp[i][j]=0;
      }
    }
    if(cc)c=cc;
    for(i=0;i<n;i++)
    {
      for(j=0;j<m;j++)
      {
        map[i][j]=temp[i][j];
      }
    }
  }
  printf("%d\n%d",s-1,c);
}
