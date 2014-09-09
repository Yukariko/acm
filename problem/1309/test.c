main()
{
  int n;
  int i=1,j=1;
  for(scanf("%d",&n);n--;)
  {
    i=i*2+j;
    j=(i-j)/2;
    if(i>=9901)i%=9901;
  }
  printf("%d",i);
}
