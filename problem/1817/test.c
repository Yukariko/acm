main()
{
  int N,M,K;
  int res=0,s=0;
  scanf("%d%d",&N,&M);
  if(N==0)return puts("0"),0;
  for(;N--;)
  {
    scanf("%d",&K);
    if(s+K>M)
    {
      s=K;
      res++;
    }
    else s+=K;
  }
  printf("%d",res+1);
}
