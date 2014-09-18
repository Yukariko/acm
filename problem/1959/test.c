main()
{
  long long s,m,n;
  scanf("%lld%lld",&m,&n);
  s=m>n?2*n-1:2*m-2;
  printf("%lld\n%lld %lld",s,s%4>=1&&s%4<=2?m-s/4:1+(s+1)/4,s%4<=1?n-s/4:1+s/4);
}
