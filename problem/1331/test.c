#define ABS(a) (a>0?a:-(a))
main()
{
  int i,j;
  int x,y;
  int tx=0,ty=0;
  int sx,sy;
  char chess[6][6]={};
  char a[3];
  gets(a);
  sx=tx=a[0]-'A';sy=ty=a[1]-'1';
  chess[tx][ty]=1;
  for(i=1;i<36;i++)
  {
    gets(a);
    x=a[0]-'A';y=a[1]-'1';
    if(ABS(x-tx)==3||ABS(y-ty)==3||ABS(x-tx)+ABS(y-ty)!=3){puts("Invalid");return;}
    chess[x][y]=1;
    tx=x;ty=y;
  }
  for(i=0;i<6;i++)for(j=0;j<6;j++)if(chess[i][j]==0){puts("Invalid");return;}
  if(ABS(x-sx)==3||ABS(y-sy)==3||ABS(x-sx)+ABS(y-sy)!=3){puts("Invalid");}
  else puts("Valid");
}
