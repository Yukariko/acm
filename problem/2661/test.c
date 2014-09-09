int a[81];
isGood(n)
{
  int i,j,k;
  k=n/2;
  int p,q,s;
  for(i=1;i<=k;i++)
  {
    s=0;
    for(p=0;p<i;p++)
    {
      if(a[n-i+p]==a[n-i*2+p])s++;
    }
    if(s==i)return 0;
  }
  return 1;
}
main()
{
  int n;
  scanf("%d",&n);
  int i,j,k;
  for(i=0;i<n;)
  {
    j=a[i]+1;
    for(;j<=3;j++)
    {
      a[i]=j;
      if(isGood(i+1))break;
    }
    if(j==4)
    {
      a[i]=0;
      i--;
    }
    else
    {
      i++;
    }
  }
  for(i=0;i<n;i++)printf("%d",a[i]);
}
