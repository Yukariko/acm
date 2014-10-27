main()
{
  int N,B,H,W;
  int res=500001;
  int i,j,k;
  scanf("%d%d%d%d",&N,&B,&H,&W);
  for(i=0;i<H;i++)
  {
    int P;
    scanf("%d",&P);
    for(j=0;j<W;j++)
    {
      int A;
      scanf("%d",&A);
      if(A>=N && P < res)
      {
        res = P;
      }
    }
  }
  res *= N;
  if(res > B) return puts("stay home"),0;
  printf("%d",res);
}
