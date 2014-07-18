int N,r,c,k,s;
main()
{
  for(;~scanf("%d%d%d",&N,&r,&c);)
  {
    s=0;
    for(N=1<<N-1;N;N/=2)
    {
      s+=N*N*(r/N*2+c/N);
      r%=N;
      c%=N;
    }
    printf("%d\n",s);
  }
}
