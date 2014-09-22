int a[1000001];
main()
{
  int n,m;
  scanf("%d%d",&n,&m);
  int i;
  int max,min;
  scanf("%d",a);
  max=min=a[0];
  for(i=1;i<n;i++)
  {
    scanf("%d",a+i);
    if(max<a[i])
    {
      max=a[i];
    }
    else if(min>a[i])
    {
      min=a[i];
    }
  }
  int mid;
  int res=m,sel;
  for(;min<=max;)
  {
    mid=(max+min)/2;
    long long s=0;
    for(i=0;i<n;i++)if(mid<a[i])s+=a[i]-mid;
    if(s>=m)
    {
      min=mid+1;
      if(res>s-m)
      {
        res=s-m;
        sel=mid;
      }
    }
    else if(s<m)max=mid-1;
  }
  printf("%d",sel);
}
