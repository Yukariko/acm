int arr[1000001];
long long hund[10001];
main()
{
  int n,m,k;
  scanf("%d%d%d",&n,&m,&k);
  int i;
  for(i=1;i<=n;i++)
  {
    scanf("%d",arr+i);
    hund[i/100]+=arr[i];
  }
  m+=k;
  for(;m--;)
  {
    int c,a,b;
    scanf("%d%d%d",&c,&a,&b);
    if(c==1)
    {
      hund[a/100]+=b-arr[a];
      arr[a]=b;
    }
    else
    {
      if(a>b){c=a;a=b;b=c;}
      long long s=0;
      for(;a<=b;)
      {
        if(a%100||b-a<100)
        {
          s+=arr[a];
          a++;
        }
        else
        {
          s+=hund[a/100];
          a+=100;
        }
      }
      printf("%lld\n",s);
    }
  }
}
