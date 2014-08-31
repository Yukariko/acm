char map[65][65];
f(i,j,n)
{
  int p,q;
  char check=map[i][j];
  for(p=0;p<n;p++)
  {
    for(q=0;q<n;q++)
    {
      if(map[i+p][j+q]!=check)break;
    }
    if(q!=n)break;
  }
  if(p==n)
  {
    printf("%c",check);
  }
  else
  {
    printf("(");
    n/=2;
    f(i,j,n);
    f(i,j+n,n);
    f(i+n,j,n);
    f(i+n,j+n,n);
    printf(")");
  }
}
main()
{
  int n;
  scanf("%d ",&n);
  int i;
  for(i=0;i<n;i++)gets(map[i]);
  f(0,0,n);
}
