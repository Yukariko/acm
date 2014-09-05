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

isPrime(n)
{
  for(int i=2;i*i<=n;i++)if(n%i==0)return 0;
  return 1;
}
putn(n,m,p)
{
  return n-(n/p%10)*p+m*p;
}
main()
{
  char che[10001]={};
  int i,j,k=0;
  for(i=2;i<=10000;i++)
  {
    if(che[i]==0)
    {
      for(j=i*i;j<=10000;j+=i)che[j]=1;
    }
  }
  int t;
  for(scanf("%d",&t);t--;)
  {
    char check[10001]={};
    int p,q,s,count;
    scanf("%d%d",&p,&q);
    Queue *queue=CreateQueue();
    qPush(queue,p);
    for(s=0;queue->count;s++)
    {
      count=queue->count;
      qData data,tmp;
      for(;count;count--)
      {
        data=qPop(queue);
        if(data==q)break;
        for(int i=1;i<=1000;i*=10)
        {
          for(int j=0;j<=9;j++)
          {
            tmp=putn(data,j,i);
            if(tmp>1000&&che[tmp]==0&&check[tmp]==0){qPush(queue,tmp);check[tmp]=1;}
          }
        }
      }
      if(count)break;
    }
    if(count)printf("%d\n",s);
    else puts("Impossible");
  }
}
