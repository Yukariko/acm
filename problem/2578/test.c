int bingo[6][6];
int n;

f()
{
  int i,j,t=0,width,height,diagonal;
  
  for(i=0;i<5;i++)
  {    
    for(width=height=j=0;j<5;j++)
    {
      width+=bingo[i][j];
      height+=bingo[j][i];
    }
    if(!width)t++;
    if(!height)t++;
  }
  diagonal=bingo[0][0]+bingo[1][1]+bingo[2][2]+bingo[3][3]+bingo[4][4];
  if(!diagonal)t++;
  diagonal=bingo[4][0]+bingo[3][1]+bingo[2][2]+bingo[1][3]+bingo[0][4];
  if(!diagonal)t++;
  return t;
}
main()
{
  int i,j,k;
  for(i=0;i<5;i++)
  {
    for(j=0;j<5;j++)
    {
      scanf("%d",&bingo[i][j]);
    }
  }
  for(i=0;i<25;i++)
  {
    scanf("%d",&n);
    for(j=0;j<5;j++)for(k=0;k<5;k++)
    {
      if(bingo[j][k]==n)
      {
        bingo[j][k]=0;
        break;
      }
    }
    if(f()>=3){printf("%d",i+1);break;}
  }
}
