main()
{
  int a,b,n;
  scanf("%d%d%d",&a,&b,&n);
  a%=b;
  int i,s=0;
  for(i=0;i<n;i++)
  {
    a*=10;
    s=a/b;
    a%=b;
  }
  printf("%d",s);
}
