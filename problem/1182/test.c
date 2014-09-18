int a[21];
int n,s;
int count;
f(p,r,c)
{
  if(c==0){count+=r==s;return;}
  int i,t=n-c;
  for(i=p;i<=t;i++)
  {
    f(i+1,r+a[i],c-1);
  }
}
main()
{
  int res=0;
  scanf("%d%d",&n,&s);
  int i;
  for(i=0;i<n;i++)scanf("%d",a+i);
  for(i=1;i<=n;i++)
  {
    f(0,0,i);
  }
  printf("%d",count);
}
