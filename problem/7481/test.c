f(A,B,S)
{
  int i,j,val,res;
  res = S / B;
  val = (S - res * B) % A;
  for(;val&&res;)
  {
    val = (val + B) % A;
    res--;
  }
  return res;
}
main()
{
  int T;
  for(scanf("%d",&T);T--;)
  {
    int A,B,S;
    int resA,resB;
    scanf("%d%d%d",&A,&B,&S);
    if(A > B)
    {
      resA = f(B,A,S);
      resB = (S-A*resA)/B;
    }
    else
    {
      resB = f(A,B,S);
      resA = (S-B*resB)/A;
    }
    if(resA * A + resB * B != S)puts("Impossible");
    else printf("%d %d\n",resA,resB);
  }
}
