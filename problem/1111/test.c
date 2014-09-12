main()
{
  int n;
  int a[51];
  int i;
  scanf("%d",&n);
  for(i=0;i<n;scanf("%d",a+i++));
  int p,q;
  if(n==1)return puts("A"),0;
  if(n==2)
  {
    if(a[0]==a[1])return printf("%d",a[0]),0;
    return puts("A"),0;
  }
  if(n>2)
  {
    p=1;
    if(a[1]-a[0])p=(a[2]-a[1])/(a[1]-a[0]);
    q=a[1]-a[0]*p;
    for(i=0;i<n-1;i++)
    {
      if(a[i]*p+q!=a[i+1])return puts("B"),0;
    }
    printf("%d",a[n-1]*p+q);
  }
}
