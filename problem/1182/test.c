int a[21];
int n,s;
int count;
f(p,r,c)
{
  if(c==0&&r==s)count++;
  if(p>=n)return;
  f(p+1,r+a[p],0);
  f(p+1,r,1);
}
main()
{
  scanf("%d%d",&n,&s);
  for(int i=0;i<n;i++)scanf("%d",a+i);
  f(0,0,1);
  printf("%d",count);
}
