s;k;x=1;
main(N,M)
{
  for(scanf("%d%d%d",&N,&M,&k);~scanf("%d",&N);)
  {
    if(N<x){s+=x-N;x=N;}
    else if (x+M<=N){s+=N-x-M+1;x=N-M+1;}
  }
  printf("%d",s);
}
