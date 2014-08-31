char digit[5][50];
f(i,j)
{
  int p,q;
  int k[3]={};
  for(q=0;q<3;q++)
  {
    for(p=0;p<5;p++)
    {
      if(digit[i+p][j+q]=='*')k[q]++;
    }
  }
  if(k[0]==5&&k[2]==5)
  {
    if(k[1]==2&&digit[i][j+1]=='*'&&digit[i+4][j+1]=='*')return 0;
    else if(k[1]==3&&digit[i][j+1]=='*'&&digit[i+2][j+1]=='*'&&digit[i+4][j+1]=='*')return 8;
  }
  if(k[0]==0&&k[1]==0&&k[2]==5)return 1;
  if(k[0]==4&&k[1]==3&&k[2]==4)
  {
    if(digit[i+1][j+1]==' '&&digit[i+3][j+1]==' ')
    {
      if(digit[i+1][j]==' '&&digit[i+3][j+2]==' ')return 2;
      if(digit[i+3][j]==' '&&digit[i+1][j+2]==' ')return 5;
    }
  }
  if(k[0]==3&&k[1]==3&&k[2]==5)
  {
    if(digit[i+1][j]==' '&&digit[i+3][j]==' '&&digit[i+1][j+1]==' '&&digit[i+3][j+1]==' ')return 3;
  }
  if(k[0]==3&&k[1]==1&&k[2]==5)
  {
    if(digit[i+3][j]==' '&&digit[i+4][j]==' '&&digit[i+2][j+1]=='*')return 4;
  }
  if(k[0]==5&&k[1]==3&&k[2]==4)
  {
    if(digit[i+1][j+1]==' '&&digit[i+3][j+1]==' '&&digit[i+1][j+2]==' ')return 6;
  }
  if(k[0]==1&&k[1]==1&&k[2]==5)
  {
    if(digit[i][j]=='*'&&digit[i][j+1]=='*')return 7;
  }
  if(k[0]==4&&k[1]==3&&k[2]==5)
  {
    if(digit[i+3][j]==' '&&digit[i+1][j+1]==' '&&digit[i+3][j+1]==' ')return 9;
  }
  return -1;
}
main()
{
  
  int i,s=0,t;
  for(i=0;i<5;i++)gets(digit[i]);
  for(i=0;digit[0][i];i+=4)
  {
    t=f(0,i);
    if(t==-1){puts("BOOM!!");return;}
    s+=t;
    s*=10;
  }
  s/=10;
   puts(s%6?"BOOM!!":"BEER!!");
}
