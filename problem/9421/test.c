int stack[1000001];
int noPrime[1000001];
int n;

f(p)
{
  int i,s=0,t;
  
  if(stack[p])return stack[p];
  
  for(i=p;i;i/=10)
  {
    s+=(i%10)*(i%10);
  }
  if(s==1){stack[p]=1;return 1;}
  stack[p]=-1;
  stack[p]=f(s);
}

main()
{
  int i,j;
  scanf("%d",&n);
  for(i=2;i*i<=n;i++)
  {
    for(j=i*i;j<=n;j+=i)noPrime[j]=1;
  }
  for(i=2;i<=n;i++)
  {
    if(!noPrime[i])
    {
      if(f(i)==1)
        printf("%d\n",i);
    }
  }
}

