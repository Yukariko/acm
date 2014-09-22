typedef struct node{int w,v;} hDATA;
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
/*int hMaxCompare(hDATA p,hDATA q)
{
  return p>q;
}*/
int hMinCompare(hDATA p,hDATA q)
{
  return p.w<q.w;
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

typedef struct pair{int w,v;} qData;
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

hDATA make_pair(int w,int v)
{
  hDATA data;
  data.w=w;
  data.v=v;
  return data;
}
qData make_qpair(int w,int v)
{
  qData data;
  data.w=w;
  data.v=v;
  return data;
}

int N,E;
int isINF;
const int INF=987654321;
Queue *adj[801];
Dijkstra(int r,int end)
{
  int dist[N+1];
  int i,j,k,w,v;
  hDATA data;
  
  for(i=1;i<=N;i++)dist[i]=INF;
  dist[r]=0;
  
  Heap *heap=CreateHeap(N+1,MIN_HEAP);
  hInsert(heap,make_pair(0,r));
  for(;heap->count;)
  {
    data=hDelete(heap);
    w=data.w;
    v=data.v;
    
    if(dist[v]<w)continue;
    LinkedList *p=adj[v]->head;
    for(i=0;i<adj[v]->count;i++)
    {
      if(dist[p->data.v] > w+p->data.w)
      {
        dist[p->data.v]=w+p->data.w;
        hInsert(heap,make_pair(w+p->data.w,p->data.v));
      }
      p=p->next;
    }
  }
  return dist[end];
}

main()
{
  scanf("%d%d",&N,&E);
  int i,j;
  for(i=1;i<=N;i++)adj[i]=CreateQueue();
  int x,y,w;
  for(i=0;i<E;i++)
  {
    scanf("%d%d%d",&x,&y,&w);
    qPush(adj[x],make_qpair(w,y));
    qPush(adj[y],make_qpair(w,x));
  }
  int sx,sy;
  scanf("%d%d",&sx,&sy);
  int a,b,c,d,e;
  a=Dijkstra(1,sx);
  b=Dijkstra(1,sy);
  c=Dijkstra(sx,sy);
  d=Dijkstra(sx,N);
  e=Dijkstra(sy,N);
  long long res1,res2;
  if(a>=INF||c>=INF||e>=INF) res1=INF;
  else res1=a+c+e;
  if(b>=INF||c>=INF||d>=INF) res2=INF;
  else res2=b+c+d;
  
  res1=res1<res2?res1:res2;
  
  printf("%d",res1==INF?-1:res1);
  
}
