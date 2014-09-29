cmp(int *a,int *b){return *a>*b?1:*a<*b?-1:0;}
int fib[43];
int res[43];
f(p,s,c)
{
  int r=0;
  if(s==0)return c;
  if(p<0)return -1;
  if(fib[p]<=s)
  {
    res[c]=fib[p];
    r=f(p-1,s-fib[p],c+1);
  }
  if(r==-1||fib[p]>s)return f(p-1,s,c);
  return r;
}
main()
{
  int i=1,j=0,k=0;
  for(;i<=1000000000;)
  {
    fib[k++]=i;
    i+=j;
    j=i-j;
  }
  int t;
  for(scanf("%d",&t);t--;)
  {
    int n;
    scanf("%d",&n);
    j=f(k-1,n,0);
    qsort(res,j,4,cmp);
    for(i=0;i<j;i++)printf("%d ",res[i]);
    puts("");
  }
}
