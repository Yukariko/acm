int min(int a,int b){return a>b?b:a;}

main()
{
  int N;
  for(int T=1;scanf("%d",&N),N;T++)
  {
    int rA,rB,rC;
    scanf("%d%d%d",&rA,&rB,&rC);
    rA=rB;
    rC+=rB;
    for(int i=1;i<N;i++)
    {
      int A,B,C;
      int tA,tB,tC;
      scanf("%d%d%d",&A,&B,&C);
      tA = A + min(rA,rB);
      tB = B + min(min(min(rA,rB),rC),tA);
      tC = C + min(min(rB,rC),tB);
      rA = tA;
      rB = tB;
      rC = tC;
    }
    printf("%d. %d\n",T,rB);
  }
}
