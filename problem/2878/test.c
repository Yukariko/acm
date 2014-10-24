typedef long long hDATA;
typedef struct Heap{
  hDATA *arr;
  int count;
  int capacity;
  int (*compare)(hDATA p,hDATA q);
}Heap;
#define MAX_HEAP hMaxCompare
#define MIN_HEAP hMinCompare
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
hDATA hTop(Heap *h)
{
  return h->arr[0];
}
int hMaxCompare(hDATA p,hDATA q)
{
  return p>q;
}
int hMinCompare(hDATA p,hDATA q)
{
  return p<q;
}
Heap *CreateHeap(int capacity, int (*compare)(hDATA p,hDATA q))
{
  Heap *h=(Heap *)malloc(sizeof(Heap));
  h->count=0;
  h->capacity=capacity;
  h->compare=compare;
  h->arr=(hDATA *)malloc(sizeof(hDATA)*capacity);
  return h;
}
void DownHeap(Heap *h, int i)
{
  int l,r,max;
  hDATA t;
  l=hLeftChild(h,i);
  r=hRightChild(h,i);
  if(l!=-1&&hMaxCompare(h->arr[l],h->arr[i]))max=l;
  else max=i;
  if(r!=-1&&hMaxCompare(h->arr[r],h->arr[max]))max=r;
  if(max!=i)
  {
    t=h->arr[i];
    h->arr[i]=h->arr[max];
    h->arr[max]=t;
    DownHeap(h,max);
  }
}
void UpHeap(Heap *h, int i)
{
  hDATA data=h->arr[i];
  int p;
  for(p=hParent(h,i);p!=-1&&hMaxCompare(data,h->arr[p]);p=hParent(h,i))
  {
    h->arr[i]=h->arr[p];
    i=p;
  }
  h->arr[i]=data;
}
hDATA hDelete(Heap *h)
{
  hDATA data={0};
  if(h->count==0)return data;
  data=h->arr[0];
  h->arr[0]=h->arr[h->count-1];
  h->count--;
  DownHeap(h,0);
  return data;
}
void hDeleteIndex(Heap *h,int i)
{
  if(h->count==0||i>=h->count)return;
  h->arr[i]=h->arr[h->count-1];
  h->count--;
  UpHeap(h,i);
}
void ResizeHeap(Heap *h)
{
  hDATA *arr_old=h->arr;
  int i;
  h->arr=(hDATA *)malloc(sizeof(hDATA)*h->capacity*2);
  for(i=0;i<h->capacity;i++)h->arr[i]=arr_old[i];
  h->capacity*=2;
  free(arr_old);
}
int hInsert(Heap *h, hDATA data)
{
  if(h->count==h->capacity)ResizeHeap(h);
  h->arr[h->count++]=data;
  UpHeap(h,h->count-1);
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
  for(i=(n-1)/2;i>=0;i--)DownHeap(h,i);
}
int M,N;
int a[100001];
bSearch(max)
{
  int start,mid,end;
  long long s;
  
  start = 1;
  end = max;
  for(;start<=end;)
  {
    mid = (start + end)/2;
    
    s=0;
    for(int i=0;i<N;i++)
    {
      if(mid < a[i]) s+= a[i]-mid;
    }
    if(s > M) start = mid + 1;
    else if (s < M) end = mid - 1;
    else break;
  }
  return mid;
}

main()
{

  int i,j,k;
  int max=0;
  
  scanf("%d%d",&M,&N);
  for(i=0;i<N;i++)
  {
    scanf("%d",&a[i]);
    max=max<a[i]?a[i]:max;
  }
  int mid = bSearch(max);
  
  for(i=0;i<N;i++)
  {
    if(a[i]>mid)
    {
      k = a[i]-mid;
      M-=
      a[i]=mid;
    }
    if(M==0)break;
  }
  Heap *heap = CreateHeap(N+1,MAX_HEAP);
  for(i=0;i<N;i++)hInsert(heap,a[i]);
  for(;M;)
  {
    k = hDelete(heap);
    i = k - hTop(heap);
    if(i<=0)i=1;
    i = M < i ? M : i;
    M-=i;
    hInsert(heap,k-i);
  }
  
  unsigned long long res=0;
  for(i=0;i<heap->count;i++)
  {
    k = heap->arr[i];
    res+=(unsigned long long)k*k;
  }
  printf("%llu",res);
}
