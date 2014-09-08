char map[101][101];
int h,w;
int isb;
f(i,j)
{
  if(i<0||i>=h||j<0||j>=w){isb=1;return 0;}
  if(map[i][j]!='.')return 0;
  map[i][j]=0;
  return 1+f(i-1,j)+f(i+1,j)+f(i,j-1)+f(i,j+1);
}
p(i,j,s)
{
  char t=map[i][j];
  map[i][j]=1;
  if(t=='/')
  {
    if(i>0&&j<w-1&&map[i-1][j+1]=='/')return p(i-1,j+1,s+1);
    if(i<h-1&&j>0&&map[i+1][j-1]=='/')return p(i+1,j-1,s+1);
    if(i<h-1&&map[i+1][j]=='\\')return p(i+1,j,s+1);
    if(j<w-1&&map[i][j+1]=='\\')return p(i,j+1,s+1);
    if(i>0&&map[i-1][j]=='\\')return p(i-1,j,s+1);
    if(j>0&&map[i][j-1]=='\\')return p(i,j-1,s+1);
  }
  else if(t=='\\')
  {
    if(i<h-1&&j<w-1&&map[i+1][j+1]=='\\')return p(i+1,j+1,s+1);
    if(i>0&&j>0&&map[i-1][j-1]=='\\')return p(i-1,j-1,s+1);
    if(i<h-1&&map[i+1][j]=='/')return p(i+1,j,s+1);
    if(j<w-1&&map[i][j+1]=='/')return p(i,j+1,s+1);
    if(i>0&&map[i-1][j]=='/')return p(i-1,j,s+1);
    if(j>0&&map[i][j-1]=='/')return p(i,j-1,s+1);
  }
}
main()
{
  scanf("%d%d ",&h,&w);
  int i,j;
  for(i=0;i<h;i++)
  {
    gets(map[i]);
  }
  int s=0,k=0,t;
  for(i=0;i<h;i++)
  {
    for(j=0;j<w;j++)
    {
      if(map[i][j]=='/'){p(i,j,0);break;}
    }
    if(j!=w)break;
  }
  for(i=0;i<h;i++)
  {
    for(j=0;j<w;j++)
    {
      if(map[i][j]==1)s++;
      else if(map[i][j]=='.')
      {
        isb=0;
        t=f(i,j);
        if(isb==0)k+=t;
      }
    }
  }
  printf("%d",s%2?0:s/2+k);
}
