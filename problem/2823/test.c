int r,c;
int sx,sy;
int numLoad,count,end;
char map[11][11];
char visit[5][11][11];
isOK(x,y,t)
{
  return x<0||y<0||x>=r||y>=c||visit[t][x][y]||map[x][y]!='.'?0:1;
}
f(x,y,t1,t2)
{
  if(end)return;
  visit[t1][x][y]++;
  if(count==0 && x==sx && y==sy){end=1;return;}
  count--;
  int res=0;
  if(isOK(x-1,y,3) && t1!=1 && t2!=1){res++;f(x-1,y,3,t1);}
  if(isOK(x,y-1,4) && t1!=2 && t2!=2){res++;f(x,y-1,4,t1);}
  if(isOK(x+1,y,1) && t1!=3 && t2!=3){res++;f(x+1,y,1,t1);}
  if(isOK(x,y+1,2) && t1!=4 && t2!=4){res++;f(x,y+1,2,t1);}
  if(res == 0)end=2;
}

main()
{
  int i,j;
  
  scanf("%d%d ",&r,&c);
  for(i=0;i<r;i++)
  {
    gets(map[i]);
    for(j=0;map[i][j];j++)if(map[i][j]=='.')numLoad++;
  }
  
  for(i=0;i<r;i++)
  {
    for(j=0;j<c;j++)
    {
      if(map[i][j]=='.')
      {
        memset(visit,0,sizeof(visit));
        count=numLoad*4;
        end=0;
        sx=i;
        sy=j;
        f(i,j,0,0);
        if(end!=1)return puts("1"),0;
      }
    }
  }
  puts("0");
}
