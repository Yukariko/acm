char map[8][8];
isOK(i,j)
{
  return i<0||j<0||i>=8||j>=8||map[i][j]>='A'?0:1;
}
char NIGHT[2][8]={
  {-1,-1,1,1,-2,-2,2,2},
  {-2,2,-2,2,-1,1,-1,1}
};
char BISHOP[2][4]={
  {-1,1,-1,1},
  {-1,-1,1,1}
};
char ROOK[2][4]={
  {1,0,0,-1},
  {0,1,-1,0}
};
char QUEEN[2][8]={
  {1,0,0,-1,-1,1,-1,1},
  {0,1,-1,0,-1,-1,1,1}
};
char KING[2][8]={
  {0,0,1,-1,-1,-1,1,1},
  {1,-1,0,0,-1,1,-1,1}
};
check(int x,int y,char c)
{
  int i,p,q;
  if(c=='P')
  {
    if(isOK(x-1,y-1))map[x-1][y-1]=1;
    if(isOK(x+1,y-1))map[x+1][y-1]=1;
  }
  else if(c=='p')
  {
    if(isOK(x-1,y+1))map[x-1][y+1]=1;
    if(isOK(x+1,y+1))map[x+1][y+1]=1;
  }
  else if(c=='N'||c=='n')
  {
    for(i=0;i<8;i++)
    {
      if(isOK(x+NIGHT[0][i],y+NIGHT[1][i]))map[x+NIGHT[0][i]][y+NIGHT[1][i]]=1;
    }
  }
  else if(c=='B'||c=='b')
  {
    for(i=0;i<4;i++)
    {
      p=x+BISHOP[0][i];q=y+BISHOP[1][i];
      for(;isOK(p,q);)
      {
        map[p][q]=1;
        p+=BISHOP[0][i];
        q+=BISHOP[1][i];
      }
    }
  }
  else if(c=='R'||c=='r')
  {
    for(i=0;i<4;i++)
    {
      p=x+ROOK[0][i];q=y+ROOK[1][i];
      for(;isOK(p,q);)
      {
        map[p][q]=1;
        p+=ROOK[0][i];
        q+=ROOK[1][i];
      }
    }
  }
  else if(c=='Q'||c=='q')
  {
    for(i=0;i<8;i++)
    {
      p=x+QUEEN[0][i];q=y+QUEEN[1][i];
      for(;isOK(p,q);)
      {
        map[p][q]=1;
        p+=QUEEN[0][i];
        q+=QUEEN[1][i];
      }
    }
  }
  else if(c=='K'||c=='k')
  {
    for(i=0;i<8;i++)
    {
      if(isOK(x+KING[0][i],y+KING[1][i]))map[x+KING[0][i]][y+KING[1][i]]=1;
    }
  }
}
main()
{
  char a[100];
  for(;gets(a);)
  {
    memset(map,0,sizeof(map));
    int i,j;
    int x=0,y=0;
    for(i=0;a[i];i++)
    {
      if(a[i]=='/'){x=0;y++;}
      else if(a[i]>='1'&&a[i]<='8'){x+=a[i]-'0';}
      else map[x++][y]=a[i];
    }
    for(i=0;i<8;i++)
    {
      for(j=0;j<8;j++)
      {
        if(map[i][j]>='A')check(i,j,map[i][j]);
      }
    }
    int s=0;
    for(i=0;i<8;i++)
    {
      for(j=0;j<8;j++)
      {
        s+=map[i][j]==0;
      }
    }
    printf("%d\n",s);
  }
}
