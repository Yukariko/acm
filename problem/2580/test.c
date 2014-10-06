#define S(i,j) ((1+i/3) * (1+j/3) -1)
main()
{
  int sudoku[10][10];
  int w[9][9]={},h[9][9]={},s[9][9]={};
  int i,j;
  for(i=0;i<9;i++)
  {
    for(j=0;j<9;j++)
    {
      scanf("%d",&sudoku[i][j]);
      w[i][sudoku[i][j]]++;
      h[j][sudoku[i][j]]++;
      s[S(i,j)][sudoku[i][j]]++; 
    }
  }
} 
