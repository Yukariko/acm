#define MAX(a,b) (a>b?a:b)
int n;
char map[51][51];
numric(char c)
{
  return c=='Y'?0:c=='C'?1:c=='P'?2:c=='Z'?3:4;
}
getMax()
{
  int i,j,k,max=0;
  int p,s;
  for(i=0;i<n;i++)
  {
    for(j=0;j<n;j++)
    {
      k=numric(map[i][j]);
      s=0;
      for(p=j;k==numric(map[i][p]);p++)s++;
      max=MAX(max,s);
      s=0;
      for(p=i;k==numric(map[p][j]);p++)s++;
      max=MAX(max,s);
    }
  }
  return max;
}
main()
{
  char t;
  scanf("%d ",&n);
  int i,j,k;
  for(i=0;i<n;i++)gets(map[i]);
  int max;
  max=getMax();
  for(i=0;i<n;i++)
  {
    for(j=0;j<n;j++)
    {
      if(j && map[i][j] != map[i][j-1])
      {
        t=map[i][j];map[i][j]=map[i][j-1];map[i][j-1]=t;
        k=getMax();
        max=MAX(max,k);
        t=map[i][j];map[i][j]=map[i][j-1];map[i][j-1]=t;
      }
      if(i && map[i][j] != map[i-1][j])
      {
        t=map[i][j];map[i][j]=map[i-1][j];map[i-1][j]=t;
        k=getMax();
        max=MAX(max,k);
        t=map[i][j];map[i][j]=map[i-1][j];map[i-1][j]=t;
      }
    }
  }
  printf("%d",max);
}
