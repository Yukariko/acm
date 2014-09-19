cmp(long long *a,long long *b){return *a>*b?1:*a<*b?-1:0;}
long long absl(long long n){return n>0?n:-n;}
long long a[100001];
long long sel[3],res[3];
long long min=3000000001LL;
int n;
binary_search(long long k,int start,int end)
{
  int mid;
  while(start<=end)
  {
    mid=(start+end)/2;
    if(a[mid]+k<0)start=mid+1;
    else end=mid-1;
    if(absl(k+a[mid])<min)
    {
      min=absl(k+a[mid]);
      res[0]=sel[0];
      res[1]=sel[1];
      res[2]=a[mid];
    }
  }
}
main()
{
  scanf("%d",&n);
  int i,k;
  for(i=0;i<n;i++)scanf("%lld",a+i);
  qsort(a,n,8,cmp);
  for(k=0;k<n;k++)
  {
    sel[0]=a[k];
    for(i=k+1;i<n-1;i++)
    {
      sel[1]=a[i];
      binary_search(a[k]+a[i],i+1,n-1);
    }
  }
  qsort(res,3,8,cmp);
  printf("%lld %lld %lld",res[0],res[1],res[2]);
}
