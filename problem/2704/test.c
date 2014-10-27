vertical(H,M,S)
{
  for(int i=32;i;i>>=1)
  {
    printf("%d%d%d",!!(H&i),!!(M&i),!!(S&i));
  }
}

horizontal(H,M,S)
{
  for(int i=32;i;i>>=1)
  {
    printf("%d",!!(H&i));
  }
  for(int i=32;i;i>>=1)
  {
    printf("%d",!!(M&i));
  }
  for(int i=32;i;i>>=1)
  {
    printf("%d",!!(S&i));
  }  
}

main()
{
  int N;
  for(scanf("%d",&N);N--;)
  {
    int H,M,S;
    scanf("%d:%d:%d",&H,&M,&S);
    vertical(H,M,S);
    putchar(' ');
    horizontal(H,M,S);
    puts("");
  }
}
