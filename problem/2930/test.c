#define MAX(a,b) (a>b?a:b)
getPoint(a,b)
{
  if(a==b)return 1;
  if(a=='S')
  {
    if(b=='P')return 2;
    return 0;
  }
  if(a=='P')
  {
    if(b=='R')return 2;
    return 0;
  }
  if(b=='S')return 2;
  return 0;
}
main()
{
  int n,r;
  int i,j,k;
  char a[51];
  char b[51][51];
  scanf("%d ",&r);
  gets(a);
  scanf("%d ",&n);
  int curScore=0,maxScore=0;
  for(i=0;i<n;i++)
  {
    gets(b[i]);
    for(j=0;b[i][j];j++)curScore+=getPoint(a[j],b[i][j]);
  }
  for(i=0;i<r;i++)
  {
    int S,P,R;
    S=P=R=0;
    for(j=0;j<n;j++)
    {
      if(b[j][i]=='S')S++;
      if(b[j][i]=='P')P++;
      if(b[j][i]=='R')R++;
    }
    maxScore+=MAX(MAX(S*2+R,P*2+S),R*2+P);
  }
  printf("%d\n%d",curScore,maxScore);
}
