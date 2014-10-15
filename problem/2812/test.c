typedef struct pair{int no,val;} hData;
typedef struct Heap{
  hData *arr;
  int count;
  int capacity;
  int (*compare)(hData p,hData q);
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
hData hTop(Heap *h)
{
  return h->arr[0];
}
int hMaxCompare(hData p,hData q)
{
  return p.val>q.val;
}
int hMinCompare(hData p,hData q)
{
  return p.val<q.val;
}
Heap *CreateHeap(int capacity, int (*compare)(hData p,hData q))
{
  Heap *h=(Heap *)malloc(sizeof(Heap));
  h->count=0;
  h->capacity=capacity;
  h->compare=compare;
  h->arr=(hData *)malloc(sizeof(hData)*capacity);
  return h;
}
void DownHeap(Heap *h, int i)
{
  int l,r,max;
  hData t;
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
  hData data=h->arr[i];
  int p;
  for(p=hParent(h,i);p!=-1&&h->compare(data,h->arr[p]);p=hParent(h,i))
  {
    h->arr[i]=h->arr[p];
    i=p;
  }
  h->arr[i]=data;
}
hData hDelete(Heap *h)
{
  hData data={0};
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
  hData *arr_old=h->arr;
  int i;
  h->arr=(hData *)malloc(sizeof(hData)*h->capacity*2);
  for(i=0;i<h->capacity;i++)h->arr[i]=arr_old[i];
  h->capacity*=2;
  free(arr_old);
}
int hInsert(Heap *h, hData data)
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
void BuildHeap(Heap *h,hData A[], int n)
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
hData make_pair(no,val)
{
  hData res;
  res.no=no;
  res.val=val;
  return res;
}
char a[500001];
int sel[10];
main()
{
  int n,k,i,j,t;
  int max=0;
  scanf("%d%d ",&n,&k);
  t=n-k;
  gets(a);
  Heap *heap=CreateHeap(k+1,MAX_HEAP);
  for(j=0;j<=k;j++)
  {
    hInsert(heap,make_pair(j,a[j]));
  }
  max=hDelete(heap).no;
  for(i=0;a[i];i++)
  {
    for(;a[j]&&j<=i+k+1;j++)
    {
      hInsert(heap,make_pair(j,a[j]));
    }
    if(i==max||k==0)
    {
      putchar(a[i]);
      if(--t==0)break;
      for(;heap->count;)
      {
        hData dat=hDelete(heap);
        if(dat.no > i)
        {
          max=dat.no;
          break;
        }
      }
    }
    else
    {
      k--;
    }
  }
}
