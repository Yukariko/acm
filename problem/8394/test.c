main()
{
  int n;
  scanf("%d",&n);
  int f1=0,f2=1;
  for(;n--;)
  {
    f2=f1+f2;
    f1=f2-f1;
    f2%=10;
  }
  printf("%d",f2);
}
