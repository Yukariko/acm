main()
{
  int n;
  scanf("%d",&n);
  long long i;
  if(n<=4)return puts("4"),0;
  for(i=1;i*i<n;i++);
  if(i*(i-1)>=n)printf("%lld",2*(i-1)+2*(i-2));
  else printf("%lld",4*(i-1));
}
