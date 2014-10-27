#define S(i,j) ((j/3) + (i/3) * 3)
typedef struct Point { int x,y; } Point;
int sudoku[10][10];
int w[9]={},h[9]={},s[9]={};
Point p[100];
int N;
int find;
f(pos)
{
  if(pos == N)
  {
    find = 1;
    return;
  }
  int sp;
  int empty;
  
  sp = S(p[pos].x,p[pos].y);
  empty = w[p[pos].x];
  empty |= h[p[pos].y];
  empty |= s[sp];
  for(int i=1; i < 10; i++)
  {
    if(find)return;
    if((empty & (1<<i)) == 0)
    {
      w[p[pos].x] |= 1<<i;
      h[p[pos].y] |= 1<<i;
      s[sp] |= 1<<i;
      sudoku[p[pos].x][p[pos].y]= i;
      f(pos+1);
      w[p[pos].x] -= 1<<i;
      h[p[pos].y] -= 1<<i;
      s[sp] -= 1<<i;
    }
  }
}

main()
{
  int i,j,k;
  for(i=1;i<=81;i++)
  {
    int x,y,t;
    scanf("%d%d%d",&x,&y,&t);
    x--;y--;
    w[x]|=1<<t;
    h[y]|=1<<t;
    s[S(x,y)]|=1<<t;
    if(sudoku[x][y] == t)continue;
    sudoku[x][y]=t;    
    N = find = 0;
    
    for(j=0;j<9;j++)
    {
      for(k=0;k<9;k++)
      {
        if(sudoku[j][k] == 0)
        {
          p[N].x = j;
          p[N].y = k;
          N++;
        }
      }
    }
    
    f(0);
    if(!find) return printf("%d",i),0;
  }
  puts("-1");
}
