main()
{
  long long i,j,t;
  scanf("%lld%lld",&i,&j);
  if(i>j){t=i;i=j;j=t;}
  printf("%lld",j*(j+1)/2-i*(i+1)/2+i);
}
