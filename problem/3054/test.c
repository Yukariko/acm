char word[16];
char print[5][99];
int i,j,k,p,n;
main()
{
  n=strlen(gets(word));
  for(k=0,j=1;j<=n;j++)
  {
    for(p=0;p<5;p++)
    {
      print[0][k]=print[4][k]=p==2?j%3?'#':'*':'.';
      print[1][k]=print[3][k]=p==1||p==3?j%3?'#':'*':'.';
      print[2][k]=p==2?word[j-1]:p==0||p==4?j%3?print[2][k]=='*'?'*':'#':'*':'.';
      k++;
    }
    k--;
  }
  for(i=0;i<5;i++)puts(print[i]);
}
