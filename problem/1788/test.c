main()
{
  int n,p=0;
  scanf("%d",&n);
  if(n<0)
  {
    p=1;
    n=-n;
  }
  int i,j=0,k=1,t;
  for(i=0;i<n;i++)
  {
    t=j;
    j=j+k;
    if(j>=1000000000)j-=1000000000;
    k=t;
  }
  printf("%d\n%d",n?p&&n%2==0?-1:1:0,j);
}
