main()
{
  int k,n;
  scanf("%d%d",&k,&n);
  int t=0;
  int p;
  char c;
  for(;n--;)
  {
    scanf("%d %c",&p,&c);
    t+=p;
    if(t>=210)break;
    if(c=='T')k=k%8+1;
  }
  printf("%d",k);
}
