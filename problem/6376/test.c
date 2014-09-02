main()
{
  puts("n e");
  puts("- -----------");
  puts("0 1");
  long long i,j;
  double s=1;
  for(i=j=1;i<=9;j*=++i)
  {
    s+=(double)1/j;
    if(i==1)puts("1 2");
    if(i==2)puts("2 2.5");
    if(i>2)printf("%lld %.9lf\n",i,s);
  }
}
