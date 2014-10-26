#define S(i,j) ((j/3) + (i/3) * 3)
typedef struct Point { int x,y; } Point;
int sudoku[10][10];
int w[9]={},h[9]={},s[9]={};
Point p[100];
int N;
f(pos)
{
  if(pos == N)
  {
    for(int i=0;i<9;i++)
    {
      for(int j=0;j<9;j++)
      {
        printf("%d ",sudoku[i][j]);
      }
      puts("");
    }
    exit(0);
  }
  int sp;
  int empty;
  
  sp = S(p[pos].x,p[pos].y);
  empty = w[p[pos].x];
  empty |= h[p[pos].y];
  empty |= s[sp];
  for(int i=1; i < 10; i++)
  {
    if((empty & (1<<i)) == 0)
    {
      w[p[pos].x] |= 1<<i;
      h[p[pos].y] |= 1<<i;
      s[sp] |= 1<<i;
      sudoku[p[pos].x][p[pos].y] = i;
      f(pos+1);
      w[p[pos].x] -= 1<<i;
      h[p[pos].y] -= 1<<i;
      s[sp] -= 1<<i;
    }
  }
}

main()
{
  int i,j,k=0;
  for(i=0;i<9;i++)
  {
    for(j=0;j<9;j++)
    {
      scanf("%d",&sudoku[i][j]);
      if(sudoku[i][j])
      {
        w[i]|=1<<sudoku[i][j];
        h[j]|=1<<sudoku[i][j];
        s[S(i,j)]|=1<<sudoku[i][j];
      }
      else
      {
        p[k].x = i;
        p[k].y = j;
        k++;
      }
    }
  }
  N = k;
  f(0);
}
