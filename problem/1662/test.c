main()
{
  char S[51];
  int stk[51]={};
  int mult[51];
  int sp;
  int i;
  
  gets(S);
  
  for(sp=i=0;S[i];i++)
  {
    if(S[i] == '('){stk[sp]--; sp++; mult[sp] = S[i-1] - '0'; }
    else if(S[i] == ')'){stk[sp-1] += mult[sp] * stk[sp]; stk[sp] = 0; sp--;}
    else
    {
      stk[sp]++;
    }
  }
  printf("%d",stk[0]);
}
