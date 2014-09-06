int a[7];
int n;
int min=987654321,max;
isPrime(p)
{
  int i;
  if(p<=1)return 0;
  for(i=2;i*i<=p;i++)
  {
    if(p%i==0)return 0;
  }
  return 1;
}
f(s,k)
{
  int i,t;
  if(k==n){if(isPrime(s)){min=min>s?s:min;max=max<s?s:max;}return;}
  for(i=0;i<n;i++)
  {
    if(a[i])
    {
      t=a[i];a[i]=0;
      f(s+t,k+1);f(s-t,k+1);f(t-s,k+1);
      f(s*t,k+1);f(s/t,k+1);if(s)f(t/s,k+1);
      a[i]=t;
    }
  }
}
main()
{
  scanf("%d",&n);
  int i,t;
  for(i=0;i<n;scanf("%d",a+i++));
  for(i=0;i<n;i++)
  {
    t=a[i];a[i]=0;
    f(t,1);a[i]=t;
  }
  if(min==987654321)puts("-1");
  else printf("%d\n%d",min,max);
}
