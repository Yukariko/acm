main()
{
  char a[101];
  int stack[101]={};
  gets(a);
  int i,k,t;
  for(i=k=0;a[i];i++)
  {
    if(a[i]=='(')t=stack[++k]=0;
    if(a[i]==')')t=stack[k--];
    if(a[i]=='H')t=1;
    if(a[i]=='C')t=12;
    if(a[i]=='O')t=16;
    if(a[i]>='1'&&a[i]<='9')t=t*(a[i]-'1');
    stack[k]+=t;
  }
  printf("%d",stack[0]);
}
