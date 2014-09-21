main()
{
  int n;
  int i=0,j=1,p=3,q=3;
  for(scanf("%d",&n);n>3;n--)
  {
    i+=j;
    j+=p;
    p+=q;
    q++;
  }
  printf("%d",i);
}
