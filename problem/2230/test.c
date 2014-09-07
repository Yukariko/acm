#define MIN(a,b) (a>b?b:a)
cmp(int *a,int *b){return *a>*b?1:*a<*b?-1:0;}
binary_search(int *arr,int size,int num)
{
  int start=0,end=size-1,mid;
  for(;start<=end;)
  {
    mid=(start+end)/2;
    if(num>arr[mid])start=mid+1;
    else if(num<arr[mid])end=mid-1;
    else return mid;
  }
  return start;
}
main()
{
  int n,m;
  int a[100001];
  scanf("%d%d",&n,&m);
  int i,j;
  for(i=0;i<n;i++)
  {
    scanf("%d",a+i);
  }
  qsort(a,n,4,cmp);
  int min=2000000001;
  for(i=0;i<n;i++)
  {
    j=binary_search(a,n,a[i]+m);
    if(j<n)min=MIN(min,a[j]-a[i]);
  }
  printf("%d",min);
}
