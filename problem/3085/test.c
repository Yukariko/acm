#define MAX(a,b) (a>b?a:b)
int n;
numric(char c){return c=='Y'?0:c=='C'?1:c=='P'?2:3;}
isOK(i,j){return i<0||j<0||i>=n||j>=n?0:1;}
main()
{
  char map[51][51];
  scanf("%d ",&n);
  int i,j,k;
  for(i=0;i<n;i++)gets(map[i]);
  int r[51][4]={};
  int c[51][4]={};
  int swapR[51][4]={};
  int swapC[51][4]={};
  for(i=0;i<n;i++)
  {
    for(j=0;j<n;j++)
    {
      k=numric(map[i][j]);
      r[i][k]++;
      c[j][k]++;
      if(isOK(i-1,j)&&map[i][j]!=map[i-1][j])swapR[i-1][k]=1;
      if(isOK(i+1,j)&&map[i][j]!=map[i+1][j])swapR[i+1][k]=1;
      if(isOK(i,j-1)&&map[i][j]!=map[i][j-1])swapC[j-1][k]=1;
      if(isOK(i,j+1)&&map[i][j]!=map[i][j+1])swapC[j+1][k]=1;
    }
  }
  int max=0;
  for(i=0;i<n;i++)
  {
    for(j=0;j<4;j++)
    {
      max=MAX(max,r[i][j]+swapR[i][j]);
      max=MAX(max,c[i][j]+swapC[i][j]);
    }
  }
  printf("%d",max);
}
