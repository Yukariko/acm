char a[5000001];
main()
{
  int n;
  scanf("%d ",&n);
  gets(a);
  long long i,s,t;
  for(s=i=0;a[i];)
  {
    if(a[i]>='1'&&a[i]<='9')
    {
      t=atol(a+i);
      if(t<1000000)s+=t;
      for(;t;t/=10)i++;
    }
    else i++;
  }
  printf("%lld",s);
}
