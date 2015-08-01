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
typedef int qData;
typedef struct LinkedList{
  qData data;
  struct LinkedList *next;
} LinkedList;
typedef struct Queue{
  LinkedList *head;
  LinkedList *tail;
  int count;
} Queue;
Queue *CreateQueue()
{
  Queue *q = (Queue *)malloc(sizeof(Queue));
  q->head=(LinkedList *)malloc(sizeof(LinkedList));
  q->head->next=0;
  q->tail=q->head;
  q->count=0;
  return q;
}
void qPush(Queue *q,qData data)
{
  q->tail->data=data;
  q->tail->next=(LinkedList *)malloc(sizeof(LinkedList));
  q->tail=q->tail->next;
  q->tail->next=0;
  q->count++;
}
qData qPop(Queue *q)
{
  qData data=q->head->data;
  LinkedList *p=q->head;
  q->head=q->head->next;
  q->count--;
  free(p);
  return data;
}
main()
{
  int edgeDownCount[32001]={};
  Queue *q[32001];
  int n,m;
  scanf("%d%d",&n,&m);
  int i,k;
  Heap *heap=CreateHeap(n+1,MIN_HEAP);
  for(i=1;i<=n;i++)q[i]=CreateQueue();
  for(i=0;i<m;i++)
  {
    int x,y;
    scanf("%d%d",&x,&y);
    qPush(q[x],y);
    edgeDownCount[y]++;
  }
  for(i=1;i<=n;i++)
  {
    if(edgeDownCount[i]==0)
    {
      hInsert(heap,i);
    }
  }
  int min;
  for(;heap->count;)
  {
    min=hDelete(heap);
    printf("%d ",min);
    for(;q[min]->count;)
    {
      i=qPop(q[min]);
      edgeDownCount[i]--;
      if(edgeDownCount[i]==0)hInsert(heap,i);
    }
  }
}