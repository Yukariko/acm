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

typedef struct point{int x,y,no;}point;
cmp(point *a,point *b)
{return a->x>b->x?1:a->x<b->x?-1:0;}
cmp2(point *a,point *b)
{return a->y>b->y?1:a->y<b->y?-1:0;}
main()
{
  int n;
  point a[100001];
  char visit[100001]={};
  scanf("%d",&n);
  int i;
  for(i=0;i<n;i++)
  {
    scanf("%d%d",&a[i].x,&a[i].y);
    no=i;
  }
  qsort(a,n,12,cmp);
  long long s=0,c=1;
  for(i=1;i<n;i++)
  {
    if(a[i].x==a[i-1].x)c++;
    else {s+=c*(c-1)/2;c=1;}
  }
  s+=c*(c-1)/2;
  c=1;
  for(i=1;i<n;i++)
  {
    if(a[i].y==a[i-1].y)c++;
    else {s+=c*(c-1)/2;c=1;}
  }
  s+=c*(c-1)/2;
  printf("%lld",s);
}
