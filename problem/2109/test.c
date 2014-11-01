typedef struct Pair { int val , no; } Pair;
typedef Pair* hDATA;
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
  return p->val>q->val;
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

Heap *d_heap[10001];

int dp[10001];
int max;
cmp(int *p,int *q){return *q-*p;}

main()
{
  int N;
  int *dp[10001];
  int i,j;
  
  scanf("%d",&N);
  for(i=0;i<=10000;i++)
  {
    d_heap[i] = CreateHeap(10,MAX_HEAP);
  }
  for(i=0;i<N;i++)
  {
    int p,d;
    scanf("%d%d",&p,&d);
    hInsert(d_heap[d],p);
  }
  
  for(i=1;i<=10000;i++)
  {
    qsort(d_heap[i]->arr,d_heap[i]->count,4,cmp);
    dp[i]=(int *)malloc(sizeof(int) * (d_heap[i]->count + 1));
  }
  
  int res = 0;
  
  for(i=1;i<=10000;i++)
  {
    int count = 0;
    dp[i][0] = 0;
    for(j=1;j <= i && j < d_heap[i]->count;j++)
    {
      count += d_heap[i]->arr[j];
      dp[i][j]=dp[i-1][j-1] + count;
      res = dp[i][j] > res ? dp[i][j] : res;
    }
  }
  
  printf("%d",res);
}
