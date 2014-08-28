typedef struct pair{int x,y;} qData;
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
  q->tail->next=(LinkedList *)malloc(sizeof(LinkedList));;
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
  int n,m;
  char map[1001][1001];
  int i,j,k;
  scanf("%d%d",&n,&m);
  Queue *queue=CreateQueue();  
  qData p,q;  
  for(i=0;i<m;i++)
  {
    for(j=0;j<n;j++)
    {
      scanf("%d",&k);
      map[i][j]=k;
      p.x=i;p.y=j;
      if(map[i][j]==1)qPush(queue,p);
    }
  }
  int b;
  for(b=i=0;!b;i++)
  {
    b=1;
    for(j=queue->count;j--;)
    {
      q=qPop(queue);
      p=q;p.x-=1;
      if(q.x>0&&map[p.x][p.y]==0)
      {
        map[p.x][p.y]=1;
        qPush(queue,p);
        b=0;
      }
      p.x+=2;
      if(q.x<m-1&&map[p.x][p.y]==0)
      {
        map[p.x][q.y]=1;
        qPush(queue,p);
        b=0;
      }
      p.x-=1;p.y-=1;
      if(q.y>0&&map[p.x][p.y]==0)
      {
        map[p.x][p.y]=1;
        qPush(queue,p);
        b=0;
      }
      p.y+=2;
      if(q.y<n-1&&map[p.x][p.y]==0)
      {
        map[p.x][p.y]=1;
        qPush(queue,p);
        b=0;
      }
    }
  }
  k=i-1;
  for(i=0;i<m;i++)for(j=0;j<n;j++)if(map[i][j]==0){puts("-1");return;}
  printf("%d",k);
}
