typedef struct animal{int l,r;}animal;
cmp(animal *a,animal *b)
{
  return a->l>b->l?1:a->l<b->l?-1:a->r>b->r?-1:a->r<b->r?1:0;
}
int stack[500001];
animal a[500001];
binary_search(int *arr,int size,int num)
{
   int start=0,end=size-1,mid;
   while(start<=end)
   {
     mid=(end+start)/2;
     if(num<arr[mid])start=mid+1;
     else if(num>arr[mid])end=mid-1;
     else return mid;
   }
   return start;
}
main()
{
  int n;
  scanf("%d",&n);
  
  
  int no,left,right;
  int i,j,k;
  for(i=0;i<n;i++)
  {
    scanf("%d%d%d",&no,&left,&right);
    a[i].l=left;
    a[i].r=right;
  }
  qsort(a,n,8,cmp);
  
  for(i=j=1;i<n;i++)
  {
    if(a[i].l!=a[i-1].l||a[i].r!=a[i-1].r)
    {
      a[j++]=a[i];
    }
  }
  n=j;
  int max=0;
  int king=0;
  k=0;
  for(i=1;i<n;i++)
  {
    if(a[i].r>a[king].r)
    {
      king=i;
      k=0;
    }
    else
    {
    
    }
    max=max<k?k:max;
  }
  printf("%d",max+1);
}
