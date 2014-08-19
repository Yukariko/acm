f(a,b){return b?f(b,a%b):a;}
main()
{
  int n;
  int r,rr;
  scanf("%d%d",&n,&r);
  for(;--n;)
  {
    scanf("%d",&rr);
    printf("%d/%d\n",r/f(r,rr),rr/f(r,rr));
  }
}
