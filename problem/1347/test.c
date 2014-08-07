char map[111][111];
int s;
char walk[51];
int x,y;
int tx,ty,t;
int i,j;
int sx,sy,ex,ey;
main()
{
  s=atoi(gets(&s));
  gets(walk);
  
  y=55;x=55;
  tx=0;ty=1;
  for(;walk[i];i++)
  {
    map[y][x]='.';
    if(walk[i]=='F')
    {
      x+=tx;
      y+=ty;
    }
    else if(walk[i]=='R')
    {
      t=tx;
      tx=-ty;
      ty=t;
    }
    else if(walk[i]=='L')
    {
      t=tx;
      tx=ty;
      ty=-t;
    }
  }
  map[y][x]='.';
  for(i=0;i<111;i++)
  {
    t=0;
    for(j=0;j<111;j++)
    {
      t+=!!map[i][j];
    }
    if(!t)sy++;
    else break;
  }
  for(i=0;i<111;i++)
  {
    t=0;
    for(j=0;j<111;j++)
    {
      t+=!!map[j][i];
    }
    if(!t)sx++;
    else break;
  }
  for(ey=i=110;i>=0;i--)
  {
    t=0;
    for(j=0;j<111;j++)
    {
      t+=!!map[i][j];
    }
    if(!t)ey--;
    else break;
  }
  for(ex=i=110;i>=0;i--)
  {
    t=0;
    for(j=0;j<111;j++)
    {
      t+=!!map[j][i];
    }
    if(!t)ex--;
    else break;
  }
  for(i=sy;i<=ey;i++)
  {
    for(j=sx;j<=ex;j++)
    {
      putchar(map[i][j]?'.':'#');
    }
    puts("");
  }
}
