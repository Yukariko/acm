int n;
long long i,j,s,t=10000000;
main()
{
  scanf("%d",&n);
  for(s=i=1;i<=n;i++)
  {
    for(j=1;j<=s*i&&s*i/j%10==0;j*=10);
    s=s*i/j%t;
  }
  printf("%lld",s%100000);
}
