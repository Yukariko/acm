main()
{
  int n,c,w;
  scanf("%d%d%d",&n,&c,&w);
  int a[1001];
  int i,max=0;
  for(i=0;i<n;i++)
  {
    scanf("%d",a+i);
    max=max<a[i]?a[i]:max;
  }
  int j,k,s,m=0,t;
  for(i=max;i;i--)
  {
    s=0;
    for(j=0;j<n;j++)
    {
      k=a[j]/i;
      t=k*i*w-(k-1+(a[j]%i?1:0))*c;
      if(t>0)s+=t;
    }
    m=m<s?s:m;
  }
  printf("%d",m);
}
