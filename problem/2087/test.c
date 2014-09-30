typedef struct pair{int p,s;long long mask;} qData;
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
qData make_qData(int p,int s,long long mask)
{
  qData data;
  data.p=p;
  data.s=s;
  data.mask=mask;
  return data;
}
main()
{
  int n,k;
  int a[41];
  scanf("%d",&n);
  int i;
  for(i=0;i<n;i++)scanf("%d",a+i);
  scanf("%d",&k);
  Queue *q=CreateQueue();
  qPush(q,make_qData(0,k,0));
  qData t;
  while(q->count)
  {
    t=qPop(q);
    if(t.p<n)
    {
      if(t.s>=a[t.p])
      {
        qPush(q,make_qData(t.p+1,t.s-a[t.p],t.mask|(1<<t.p)));
      }
      qPush(q,make_qData(t.p+1,t.s,t.mask));
    }
    if(t.s==0)
    {
      for(;t.mask;t.mask>>=1)printf("%d",t.mask&1);
      break;
    }
  }
}
