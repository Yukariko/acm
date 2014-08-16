cmp(int *a, int *b)
{
  return *a-*b;
}
main()
{
  int n,m;
  int a[10001];
  int i,j,k,s,max,lc;
  scanf("%d",&n);for(i=0;i<n;scanf("%d",a+i++));scanf("%d",&m);
  qsort(a,n,4,cmp);
  for(j=i=0;i<n;i++)if(m < j+a[i]*(n-i))break;else j+=a[i];
  printf("%d",i==n?a[n-1]:(m-j)/(n-i));
}
