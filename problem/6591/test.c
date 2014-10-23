// N! / ((N-K)! * K!)
main()
{
  int N,K;
  for(;scanf("%d%d",&N,&K),N;)
  {
    long long res=1;
    int i,r=2;
    if(N/2 < K) K = N-K;
    for(i=N;i>N-K;i--)
    {
      res*=i;
      if(res%r==0&&r<=K)
      {
        res/=r;
        r++;
      }
    }
    printf("%lld\n",res);
  }
}
