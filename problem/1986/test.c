typedef struct Chess{int x,y;}Chess;
int n,m;
char map[1001][1001];
isOK(i,j)
{
  if(i<1||j<1||i>n||j>m||map[i][j]==1)return 0;
  return 1;
}
main()
{
  scanf("%d%d",&n,&m);
  Chess queen[101];
  Chess knight[101];
  Chess pawn[101];
  int i,j;
  int q,k,p;
  scanf("%d",&q);for(i=0;i<q;i++){scanf("%d%d",&queen[i].x,&queen[i].y);map[queen[i].x][queen[i].y]=1;}
  scanf("%d",&k);for(i=0;i<k;i++){scanf("%d%d",&knight[i].x,&knight[i].y);map[knight[i].x][knight[i].y]=1;}
  scanf("%d",&p);for(i=0;i<p;i++){scanf("%d%d",&pawn[i].x,&pawn[i].y);map[pawn[i].x][pawn[i].y]=1;}
  int x,y;
  for(i=0;i<k;i++)
  {
    x=knight[i].x;
    y=knight[i].y;
    if(isOK(x-2,y-1))map[x-2][y-1]=2;
    if(isOK(x-2,y+1))map[x-2][y+1]=2;
    if(isOK(x+2,y-1))map[x+2][y-1]=2;
    if(isOK(x+2,y+1))map[x+2][y+1]=2;
    if(isOK(x-1,y-2))map[x-1][y-2]=2;
    if(isOK(x-1,y+2))map[x-1][y+2]=2;
    if(isOK(x+1,y-2))map[x+1][y-2]=2;
    if(isOK(x+1,y+2))map[x+1][y+2]=2;    
  }
  for(i=0;i<q;i++)
  {
    x=queen[i].x;
    y=queen[i].y;
    for(j=1;isOK(x-j,y);j++)map[x-j][y]=2;
    for(j=1;isOK(x+j,y);j++)map[x+j][y]=2;
    for(j=1;isOK(x,y-j);j++)map[x][y-j]=2;
    for(j=1;isOK(x,y+j);j++)map[x][y+j]=2;
    for(j=1;isOK(x-j,y-j);j++)map[x-j][y-j]=2;
    for(j=1;isOK(x-j,y+j);j++)map[x-j][y+j]=2;
    for(j=1;isOK(x+j,y-j);j++)map[x+j][y-j]=2;
    for(j=1;isOK(x+j,y+j);j++)map[x+j][y+j]=2;
  }  
  int s=0;
  for(i=1;i<=n;i++)
  {
    for(j=1;j<=m;j++)
    {
      s+=map[i][j]==0;
    }
  }
  printf("%d",s);
}
