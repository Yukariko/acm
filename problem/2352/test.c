typedef struct wire{int x,y;}wire;
cmp(wire *a,wire *b){return a->x-b->x;}
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
LIS(wire *arr,int size)
{
  int *b=(int *)malloc(size*4);
  int i,j,k=0;
  for(i=0;i<size;i++)
  {
    j=binary_search(b,k,arr[i].y);
    if(j==k)
    {
      b[k++]=arr[i].y;
    }
    else
    {
      b[j]=arr[i].y;
    }
  }
  free(b);
  return k;
}
main()
{
  int n;
  int i,j,k;
  wire a[40001];
  scanf("%d",&n);
  for(i=0;i<n;i++)
  {
    a[i].x = i+1;
    scanf("%d",&a[i].y);
  }
  qsort(a,n,8,cmp);
  printf("%d",LIS(a,n));
}
