main()
{
  int t;
  int n,h,k;
  long long i;
  for(scanf("%d",&t);t--;)
  {
    scanf("%d",&n);
    k=0;
    for(h=2;(i=n/h-(h-1)/2)>0;h++)
    {
      if((i+h)*(i+h-1)/2-(i-1)*i/2==n)k++;
    }
    printf("%d\n",k);
  }
}
