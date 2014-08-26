typedef int qData;
typedef struct LinkedList{
  qData data;
  struct LinkedList *next;
} LinkedList;
typedef struct Queue{
  LinkedList *head;
  LinkedList *tail;
} Queue;
Queue *CreateQueue()
{
  Queue *q = (Queue *)malloc(sizeof(Queue));
  q->head=(LinkedList *)malloc(sizeof(LinkedList));
  q->head->next=0;
  q->tail=q->head;
  return q;
}
void qPush(Queue *q,qData data)
{
  q->tail->next=(LinkedList *)malloc(sizeof(LinkedList));
  q->tail=q->tail->next;
  q->tail->data=data;
  q->tail->next=0;
}
typedef struct Vertex{int y,w;} hData;
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
}
int hMinCompare(hData p,hData q)
{
  return p.w<q.w;
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

int V,E;
char visit[10001];
Heap *heap[10001];
Queue *queue;
int prim(int r)
{
  qData q;
  visit[r]=1;
  qPush(queue,r);
  LinkedList *t;
  int i,sum=0;
  for(i=0;i<V;i++)
  {
    int min=1000001,v;
    hData k;
    for(t=queue->head->next;t;t=t->next)
    {
      for(;heap[t->data]->count;)
      {
        k=heap[t->data]->arr[0];
        if(visit[k.y])
        {
          hDelete(heap[t->data]);
        }
        else
        {
          if(min>k.w)
          {
        	min=k.w;
        	v=k.y;
          }
          break;
        }
      }
    }
    if(min!=1000001)
    {
      visit[v]=1;
      qPush(queue,v);
      sum+=min;
    }
    else break;
  }
  return sum;
}
main()
{
  scanf("%d%d",&V,&E);
  queue=CreateQueue();

  int x[100001],y[100001],w[100001],count[10001]={0};
  hData t;
  for(int i=0;i<E;i++)
  {
    scanf("%d%d%d",&x[i],&y[i],&w[i]);
    count[x[i]]++;
    count[y[i]]++;
  }
  for(int i=1;i<=V;i++)
  {
    heap[i]=CreateHeap(count[i],hMinCompare);
  }
  for(int i=0;i<E;i++)
  {
    t.y=y[i];t.w=w[i];
    hInsert(heap[x[i]],t);
    t.y=x[i];
    hInsert(heap[y[i]],t);
  }
  printf("%d",prim(x[0]));
}
