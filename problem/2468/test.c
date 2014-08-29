int map[101][101];
int visit[101][101];
int n;
f(i,j,s)
{
  if(visit[i][j]==s)return;
  visit[i][j]=s;
  if(i>0)f(i-1,j,s);
  if(i<n-1)f(i+1,j,s);
  if(j>0)f(i,j-1,s);
  if(j<n-1)f(i,j+1,s);
}
main()
{

  scanf("%d",&n);
  int i,j,k;
  for(i=0;i<n;i++)
  {
    for(j=0;j<n;j++)
    {
      scanf("%d",&map[i][j]);
    }
  }
  int max=1,s;
  for(i=1;i<=100;i++)
  {
    s=0;
    for(j=0;j<n;j++)
    {
      for(k=0;k<n;k++)
      {
        if(map[j][k]<=i)visit[j][k]=i;
      }
    }
    for(j=0;j<n;j++)
    {
      for(k=0;k<n;k++)
      {
        if(visit[j][k]!=i)
        {
          s++;
          f(j,k,i);
        }
      }
    }
    max=max<s?s:max;
  }
  printf("%d",max);
}

