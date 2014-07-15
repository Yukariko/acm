int i,s;
main(n)
{
  for(scanf("%d",&n);~scanf(" %c",&i);)s+=i=='L'?1:0;
  printf("%d",n-(s?s/2-1:0));
}
