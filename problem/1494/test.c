int N;
long long first,second,S0,S1,S,i;
long long absl(long long a){return a>0?a:-a;}
main()
{
  for(scanf("%lld%lld%d",&first,&second,&N);N--;)
  {
    scanf("%lld",&i);
    if(i==0||i==1)printf("%lld\n",i?second:first);
    else
    {
      S0=first;
      S1=second;
      S=absl(S0-S1);
      for(i-=3;i>=0;i--)
      {
        S0=S1;
        S1=S;
        S=absl(S0-S1);
        if(S==0)
        {
          i%=3;
        }
      }
      printf("%lld\n",S);
    }
  }
}
