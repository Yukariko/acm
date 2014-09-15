int a[100001];
int n;
binary_search(k)
{
  int start=0,end=n-1,mid;
  while(start<=end)
  {
    mid=(start+end)/2;
    if(a[mid]<k)start=mid+1;
    else if(a[mid]>k)end=mid-1;
    else return mid;
  }
  return start;
}
main()
{
  
  scanf("%d",&n);
  int i,j;
  for(i=0;i<n;i++)scanf("%d",a+i);
  int min=1000000001;
  int sa,sb,t,p;
  for(i=0;i<n;i++)
  {
    t=binary_search(-a[i]);
    if(t<=i)t=i+1;
    if(t>=n)t=n-1;
    p=abs(a[t]+a[i]);
    for(;t!=i;t--)
    {
      if(abs(a[t]+a[i])<min)
      {
        min=abs(a[t]+a[i]);
        sa=a[i];
        sb=a[t];
      }
      else if(abs(a[t]+a[i])>p)break;
    }
    if(a[i]>0)break;
  }
  printf("%d %d",sa<sb?sa:sb,sa<sb?sb:sa);
}
