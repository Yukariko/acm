typedef struct wire{int x,y;}wire;
cmp(wire *a,wire *b){return a->x-b->x;}
binary_search(int *arr,wire *orgn,int size,int num)
{
   int start=0,end=size-1,mid;
   while(start<=end)
   {
     mid=(end+start)/2;
     if(num>orgn[arr[mid]].y)start=mid+1;
     else if(num<orgn[arr[mid]].y)end=mid-1;
     else return mid;
   }
   return start;
}
LIS(wire *arr,int size,int *lis)
{
  int *b=(int *)malloc(size*4);
  int *parent = (int *)malloc(size*4);
  memset(parent,-1,size*4);
  int i,j,k=0;
  for(i=0;i<size;i++)
  {
    j=binary_search(b,arr,k,arr[i].y);
    if(j==k)
    {
      b[k++]=i;
      if(k>1)parent[i]=b[k-2];
    }
    else
    {
      b[j]=i;
      if(j)parent[i]=b[j-1];
    }
  }

  int child=b[k-1];
  while(child!=-1)
  {
  	arr[child].x = -1;
  	//printf("%d ",arr[child].y);
  	child=parent[child];
  }
  free(b);
  free(parent);
  return k;
}
main()
{
  int n;
  int i,j,k;
  wire a[100001];
  scanf("%d",&n);
  for(i=0;i<n;i++)
  {
    scanf("%d%d",&a[i].x,&a[i].y);
  }
  qsort(a,n,8,cmp);
  printf("%d\n",n-LIS(a,n,a));
  for(int i=0;i<n;i++)if(a[i].x != -1)printf("%d\n",a[i].x);
}

