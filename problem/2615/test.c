int omok[21][21];
f(x,y,t)
{
  int i,c;
  for(c=i=0;omok[x+i][y]==t;i++)c++;for(i=1;omok[x-i][y]==t;i++)c++;
  if(c==5)return 1;
  
  for(c=i=0;omok[x][y+i]==t;i++)c++;for(i=1;omok[x][y-i]==t;i++)c++;
  if(c==5)return 1;
  
  for(c=i=0;omok[x+i][y+i]==t;i++)c++;for(i=1;omok[x-i][y-i]==t;i++)c++;
  if(c==5)return 1;
  
  for(c=i=0;omok[x-i][y+i]==t;i++)c++;for(i=1;omok[x+i][y-i]==t;i++)c++;
  if(c==5)return 1;
  return 0;
}
main()
{
  int i,j;
  for(i=1;i<20;i++)
  {
    for(j=1;j<20;j++)
    {
      scanf("%d",&omok[i][j]);
    }
  }
  int win=-1,x=20,y;
  for(i=1;i<20;i++)
  {
    for(j=1;j<20;j++)
    {
      if(omok[i][j])
      {
        if(f(i,j,omok[i][j])&&j<x)
        {
          win=omok[i][j];
          x=j;
          y=i;
        }
      }
    }
  }
  if(win==-1)return puts("0"),0;
  printf("%d\n%d %d",win,y,x);
}
