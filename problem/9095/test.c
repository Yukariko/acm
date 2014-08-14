int n,t;
int count;
f(i)
{
  if(i==0){count++;return;}
  if(i<0){return;}
  f(i-1);
  f(i-2);
  f(i-3);
}
main()
{
  for(scanf("%d",&t);t--;)
  {
    scanf("%d",&n);
    count=0;
    f(n);printf("%d\n",count);
  }
}
