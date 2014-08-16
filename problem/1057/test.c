main()
{
  int n,a,b,i;
  scanf("%d%d%d",&n,&a,&b);
  for(i=0;a!=b;i++)
  {
    a=a-a/2;
    b=b-b/2;
  }
  printf("%d",i);
}
