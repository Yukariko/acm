#define num(idx) (var[idx-'A'])
main()
{
  int N;
  long double var[27];
  char calc[100];
  int i,j;
  
  scanf("%d ",&N);
  gets(calc);
  
  for(i=0;i<N;i++)
  {
    scanf("%f",var+i);
  }
  
  long double stack[100];
  int stkIdx=0;
  
  for(i=0;calc[i];i++)
  {
    if(isalpha(calc[i]))
    {
      stack[stkIdx++]=num(calc[i]);
    }
    else
    {
      stkIdx--;
      if(calc[i]=='+')stack[stkIdx-1]+=stack[stkIdx];
      if(calc[i]=='-')stack[stkIdx-1]-=stack[stkIdx];
      if(calc[i]=='*')stack[stkIdx-1]*=stack[stkIdx];
      if(calc[i]=='/')stack[stkIdx-1]/=stack[stkIdx];
    }
  }
  printf("%.2Lf",stack[0]);
}
