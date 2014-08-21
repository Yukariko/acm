typedef struct PAIR{int v,i;} hDATA;
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
int hCompare(Heap *h,hDATA p,hDATA q)
{
  if(h->heap_type==MAX_HEAP)
  {
    return p.v>q.v;
  }
  else //MIN_HEAP
  {
    return p.v<q.v;
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
void hDeleteTop(Heap *h)
{
  hDATA data;
  if(h->count==0)return;
  data=h->arr[0];
  h->arr[0]=h->arr[h->count-1];
  h->count--;
  hPercolateDown(h,0);
}
int hInsert(Heap *h, hDATA data)
{
  int i,t;
  h->count++;
  for(i=h->count-1;i>0&&hCompare(h,data,h->arr[t=(i-1)/2]);i=t)
  {
    h->arr[i]=h->arr[t];
  }
  h->arr[i]=data;
}

main()
{
  
  int t;
  Heap *h=CreateHeap(1000001,MAX_HEAP);
  Heap *h2=CreateHeap(1000001,MIN_HEAP);
  for(scanf("%d",&t);t--;)
  {
    int n;
    int i,min,s=0;
    char ck[1000001]={0};
    h->count=h2->count=0;
    for(scanf("%d",&n);n--;)
    {
      char cmd;
      int val;
      hDATA t;
      scanf(" %c %d",&cmd,&val);
      if(cmd=='I')
      {
        t.v=val;
        t.i=n;
        hInsert(h,t);
        hInsert(h2,t);
        ck[n]=1;
      }
      else
      {
        while(h->count&&!ck[h->arr[0].i])hDeleteTop(h);
        while(h2->count&&!ck[h2->arr[0].i])hDeleteTop(h2);
        if(h->count==0)continue;
        if(val==1)
        {
          ck[h->arr[0].i]=0;
          hDeleteTop(h);
        }
        else
        {
          ck[h2->arr[0].i]=0;
          hDeleteTop(h2);
        }
      }
    }
    while(h->count&&!ck[h->arr[0].i])hDeleteTop(h);
    while(h2->count&&!ck[h2->arr[0].i])hDeleteTop(h2);
    if(h->count==0||h2->count==0)puts("EMPTY");
    else
    {
      printf("%d %d\n",h->arr[0].v,h2->arr[0].v);
    }
  }
}
