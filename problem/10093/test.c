long long t,a,b;
main()
{
  scanf("%lld%lld",&a,&b);
  if(b<a){t=a;a=b;b=t;}
  printf("%lld\n",b-a?b-a-1:0);
  for(++a;a<b;printf("%lld ",a++));
}
