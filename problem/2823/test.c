#define UP 1
#define DOWN 2
#define LEFT 3
#define RIGHT 4
min(a,b){return a>b?b:a;}
char map[13][13];
int mask[13][13];
int R,C,x,y,m;
int now,past,sel;
main(i,j,k)
{
  scanf("%d%d ",&R,&C);
  for(i=1;i<=R;i++)gets(&map[i][1]);
  for(i=1;i<=R;i++)for(j=1;j<=C;j++){m+=map[i][j]=='.';x=j;y=i;}
  for(i=0;i<13;i++)for(j=0;j<13;j++)mask[i][j]=map[i][j]=='.'?0:99;
  mask[i][j]++;
  for(;;)
  {
    
    sel=min(min(min(mask[y-1][x],mask[y+1][x]),mask[y][x-1]),mask[y][x+1]);
    printf("%d %d %d %d %d\n",x,y,sel,now,past);
    if(mask[y-1][x]==sel&&now!=DOWN&&!((now==LEFT||now==RIGHT)&&past==DOWN))
    {
      past=now;
      now=UP;
      y--;
    }
    else if(mask[y+1][x]==sel&&now!=UP&&!((now==LEFT||now==RIGHT)&&past==UP))
    {
      past=now;
      now=DOWN;
      y++;
    }
    else if(mask[y][x-1]==sel&&now!=RIGHT&&!((now==UP||now==DOWN)&&past==RIGHT))
    {
      past=now;
      now=LEFT;
      x--;
    }
    else if(mask[y][x+1]==sel&&now!=LEFT&&!((now==UP||now==DOWN)&&past==LEFT))
    {
      past=now;
      now=RIGHT;
      x++;
    }
    else
    {
      puts("1");
      while(1);
      return;
    }
    
    mask[y][x]++;
    k=0;for(i=1;i<=R;i++)for(j=1;j<=C;j++)k+=mask[i][j]!=99&&mask[i][j]>0?1:0;
    if(k==m){puts("0");return;}
  }
}
