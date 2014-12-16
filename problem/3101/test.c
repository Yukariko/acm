int N,K;
long long loop_sum(int dst)
{
  long long res = ((long long)dst * (dst+1)) >> 1;
  return res;
}
long long get_point(int X,int Y)
{
  int rotation = (X+Y)&1;
  long long res;
  
  if (X+Y <= N+1)
  {
    res = loop_sum(X+Y-2);
    res += rotation? Y: X;
  }
  else
  {
    int k = N*2 - (X+Y) + 1;
    res = (long long)N*N - loop_sum(k);
    k = X+Y - (N+1);
    res += rotation? Y - k: X - k;
  }
  return res;
}

main()
{
  int X=1,Y=1;
  long long sum=1;
  char cmd;
  scanf("%d%d ",&N,&K);
  for(;K--;)
  {
    cmd = getchar();
    switch(cmd)
    {
    case 'D': Y++; break; 
    case 'R': X++; break;
    case 'U': Y--; break;
    case 'L': X--; break;
    }
    Y = Y>N?N:Y<1?1:Y;
    X = X>N?N:X<1?1:X;
    sum += get_point(X,Y);
  }
  printf("%lld",sum);
}
