int n;
char a[11];
long long min=9876543210,max;
char cMin[11],cMax[11];
char state[11];
char check[11];
f(p)
{
  
  if(p==n)
  {
    long long t;
    sscanf(state,"%lld",&t);
    if(max<t)
    {
      max=t;
      strcpy(cMax,state);
    }
    if(min>t)
    {
      min=t;
      strcpy(cMin,state);
    }
    return;
  }
  int i;
  for(i=0;i<=9;i++)
  {
    if(check[i]==0)
    {
      if(a[p]=='<'&&state[p]<i+'0')
      {
        state[p+1]=i+'0';
        check[i]=1;
        f(p+1);
        check[i]=0;
      }
      else if(a[p]=='>'&&state[p]>i+'0')
      {
        state[p+1]=i+'0';
        check[i]=1;
        f(p+1);
        check[i]=0;
      }
    }
  }
}
main()
{
  scanf("%d ",&n);
  int i;
  for(i=0;i<n;i++)scanf(" %c",a+i);
  for(i=0;i<=9;i++)
  {
    state[0]=i+'0';
    check[i]=1;
    f(0);
    check[i]=0;
  }
  puts(cMax);
  puts(cMin);
}
