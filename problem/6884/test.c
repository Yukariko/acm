isPrime(n)
{
  int i;
  for(i=2;i*i<=n;i++)if(n%i==0)return 0;
  return 1;
}
main()
{
  int t;
  int a[10001];
  for(scanf("%d",&t);t--;)
  {
    int n;
    scanf("%d",&n);
    int i,j,s,b=0;
    for(i=0;i<n;i++)scanf("%d",a+i);
    for(j=2;j<=n;j++)
    {
      for(s=i=0;i<j;i++)s+=a[i];
      if(isPrime(s))break;
      for(i=j;i<n;)
      {
        s+=a[i]-a[i-j];
        i++;
        if(isPrime(s)){b=1;break;}
      }
      if(b)break;
    }
    if(j>n)puts("This sequence is anti-primed.");
    else
    {
      printf("Shortest primed subsequence is length %d:",j);
      i-=j;
      for(s=0;s<j;s++)printf(" %d",a[i+s]);
      puts("");
    }
  }
}
