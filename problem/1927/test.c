typedef int hDATA;
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
hDATA hGetTopValue(Heap *h)
{
  return h->arr[0];
}
int hMaxCompare(hDATA p,hDATA q)
{
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
  if(l!=-1&&h->compare(h->arr[l],h->arr[i]))max=l;
  else max=i;
  if(r!=-1&&h->compare(h->arr[r],h->arr[max]))max=r;
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
  for(p=hParent(h,i);p!=-1&&h->compare(data,h->arr[p]);p=hParent(h,i))
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

main()
{
  Heap *h = CreateHeap(100001,MIN_HEAP);
  int n,k;
  for(scanf("%d",&n);n--;)
  {
    scanf("%d",&k);
    if(k==0)printf("[%d]\n",hDelete(h));
    else hInsert(h,k);
  }
}
