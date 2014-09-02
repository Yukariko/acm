binary_search(int *arr,int size,int num)
{
   int start=0,end=size-1,mid;
   while(start<=end)
   {
     mid=(end+start)/2;
     if(num>arr[mid])start=mid+1;
     else if(num<arr[mid])end=mid-1;
     else return mid;
   }
   return start;
}
LIS(int *arr,int size)
{
  int *b=(int *)malloc(size*4);
  int i,j,k=0;
  for(i=0;i<size;i++)
  {
    j=binary_search(b,k,arr[i]);
    if(j==k)
    {
      b[k++]=arr[i];
    }
    else
    {
      b[j]=arr[i];
    }
  }
  free(b);
  return k;
}
main()
{
  int n;
  scanf("%d",&n);
  int a[1001];
  int i;
  for(i=0;i<n;i++)scanf("%d",a+i);
  printf("%d",LIS(a,n));
}
