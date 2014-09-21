main()
{
  int t;
  long long a[6];
  long long b[6];
  for(scanf("%d",&t);t--;)
  {
    long long n;
    scanf("%lld",&n);
    int i,s;
    for(i=0;i<6;i++)scanf("%lld",a+i);
    long long k=0;
    for(s=1;;s++)
    {
      k=0;
      for(i=0;i<6;i++)k+=a[i];
      if(n<k)break;
      b[0]=a[0]+a[5]+a[1]+a[3];
      b[1]=a[1]+a[0]+a[2]+a[4];
      b[2]=a[2]+a[1]+a[3]+a[5];
      b[3]=a[3]+a[2]+a[4]+a[0];
      b[4]=a[4]+a[3]+a[5]+a[1];
      b[5]=a[5]+a[4]+a[0]+a[2];
      for(i=0;i<6;i++)
      {
        a[i]=b[i];
      }
    }
    printf("%d\n",s);
  }
}
