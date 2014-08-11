int n;
cmp(int *a,int *b)
{
  return *a>*b?-1:*a<*b?1:0;
}
main()
{
  int i,t;
  int max;
  int arr[100001];
  scanf("%d",&n);
  for(i=1;i<=n;scanf("%d",arr+i++));
  qsort(arr+1,n,4,cmp);
  for(max=i=1;i<=n;i++)
  {
    if(max<arr[i]+i)
      max=arr[i]+i;
  }
  printf("%d",max+1);
}
