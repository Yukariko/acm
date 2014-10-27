gcd(a,b){return b?gcd(b,a%b):a;}
main()
{
  int A,B,C;
  for(;~scanf("%d%d%d",&A,&B,&C);)
  {
    int resA,resB,t;
    resA = A*B;
    resB = C-B;
   	t = gcd(resA,resB);
    resA /= t;
    resB /= t;
    printf("%d/%d\n",resA,resB);
  }
}
