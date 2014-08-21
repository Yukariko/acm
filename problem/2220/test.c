typedef int hDATA;
typedef struct Heap{
  hDATA *arr;
  int count;
  int capacity;
  int heap_type;
}Heap;
#define MAX_HEAP 1
#define MIN_HEAP 2
Heap *CreateHeap(int capacity, int heap_type)
{
  Heap *h=(Heap *)malloc(sizeof(Heap));
  h->count=0;
  h->capacity=capacity;
  h->heap_type=heap_type;
  h->arr=(hDATA *)malloc(sizeof(hDATA)*capacity);
  return h;
}
int hParent(Heap *h, int i)
{
  if(i<=0||i>=h->count)return -1;
  return (i-1)/2;
}
int hLeftChild(Heap *h, int i)
{
  int t=2*i+1;
  if(t>=h->count)return -1;
  return t;
}
int hRightChild(Heap *h, int i)
{
  int t=2*i+2;
  if(t>=h->count)return -1;
  return t;
}
hDATA hTopValue(Heap *h)
{
  if(h->count==0) return -1;
  return h->arr[0];
}
int hCompare(Heap *h,hDATA p,hDATA q)
{
  if(h->heap_type==MAX_HEAP)
  {
    return p>q?1:0;
  }
  else //MIN_HEAP
  {
    return p<q?1:0;
  }
}
void hPercolateDown(Heap *h, int i)
{
  int l,r,max;
  hDATA t;
  l=hLeftChild(h,i);
  r=hRightChild(h,i);
  if(l!=-1&&hCompare(h,h->arr[l],h->arr[i]))max=l;
  else max=i;
  if(r!=-1&&hCompare(h,h->arr[r],h->arr[max]))max=r;
  if(max!=i)
  {
    t=h->arr[i];
    h->arr[i]=h->arr[max];
    h->arr[max]=t;
    hPercolateDown(h,max);
  }
}
hDATA hDeleteTop(Heap *h)
{
  hDATA data;
  if(h->count==0)return -1;
  data=h->arr[0];
  h->arr[0]=h->arr[h->count-1];
  h->count--;
  hPercolateDown(h,0);
  return data;
}
void ResizeHeap(Heap *h)
{
  int *arr_old=h->arr;
  int i;
  h->arr=(hDATA *)malloc(sizeof(hDATA)*h->capacity*2);
  for(i=0;i<h->capacity;i++)h->arr[i]=arr_old[i];
  h->capacity*=2;
  free(arr_old);
}
int hInsert(Heap *h, hDATA data)
{
  int i;
  if(h->count==h->capacity)ResizeHeap(h);
  h->count++;
  if(h->heap_type==MAX_HEAP)
  {
    for(i=h->count-1;i>0&&data>h->arr[(i-1)/2];i=(i-1)/2)
    {
      h->arr[i]=h->arr[(i-1)/2];
    }
  }
  else
  {
    for(i=h->count-1;i>0&&data<h->arr[(i-1)/2];i=(i-1)/2)
    {
      h->arr[i]=h->arr[(i-1)/2];
    }
  }
  h->arr[i]=data;
}
void DestroyHeap(Heap *h)
{
  if(h==0)return;
  free(h->arr);
  free(h);
}
void BuildHeap(Heap *h,hDATA A[], int n)
{
  if(h==0)return;
  while(n>h->capacity)ResizeHeap(h);
  int i;
  for(i=0;i<n;i++)
  {
    h->arr[i]=A[i];
  }
  h->count=n;
  for(i=(n-1)/2;i>=0;i--)hPercolateDown(h,i);
}


main()
{
  Heap *h=CreateHeap(100001,MAX_HEAP);
  int n;
  scanf("%d",&n);
  int i;
  hInsert(h,n);
  for(i=1;i<n;i++)hInsert(h,i);
  
  for(i=0;i<n;i++)printf("%d ",h->arr[i]);
}
