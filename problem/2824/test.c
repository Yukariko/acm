gcd(a,b){return b?gcd(b,a%b):a;}
main()
{
  int n,m;
  int a[1001];
  int i,j,k,t,b=0;
  long long s;
  scanf("%d",&n);
  for(i=0;i<n;i++)
  {
    scanf("%d",a+i);
  }
  scanf("%d",&m);
  s=1;
  for(j=0;j<m;j++)
  {
    scanf("%d",&k);
    for(i=0;i<n;i++)
    {
      if(a[i]!=1)
      {
        t=gcd(a[i],k);
        s=s*t;
        if(s>=1000000000){s%=1000000000;b=1;}
        k/=t;
        a[i]/=t;
        if(k==1)break;
      }
    }
  }
  if(!b)
  {
    for(i=j=1;i<=s;i*=10,j++);
    for(j=10-j;j--;)putchar('0');
  }
  printf("%lld",s);
}
