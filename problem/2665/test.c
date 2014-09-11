typedef struct pair{int x,y,w;} qData;
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
int point[52][52];
char visit[52][52];
char map[52][52];
char mask[52][52];
int n;
isOK(i,j)
{
  if(i>n||i<1||j>n||j<1)return 0;
  if(visit[i][j]==1)return 0;
  return 1;
}
prim()
{
  Queue *q=CreateQueue();
  LinkedList *l;
  qData data;
  data.x=data.y=1;
  data.w=0;
  visit[1][1]=1;
  qPush(q,data);
  
  int i,j,k,m;
  int x,y,w;
  int res=10001;
  for(i=n*n-1;i;)
  {
    k=q->count;
    l=q->head;
    m=10001;
    for(j=0;j<k;j++)
    {
      x=l->data.x;
      y=l->data.y;
      w=l->data.w;
      if(isOK(y-1,x)&&w+!map[y-1][x]<m)
      {
        m=w+!map[y-1][x];
      }
      if(isOK(y+1,x)&&w+!map[y+1][x]<m)
      {
        m=w+!map[y+1][x];
      }
      if(isOK(y,x-1)&&w+!map[y][x-1]<m)
      {
        m=w+!map[y][x-1];
      }
      if(isOK(y,x+1)&&w+!map[y][x+1]<m)
      {
        m=w+!map[y][x+1];
      }
      l=l->next;
    }
    l=q->head;
    for(j=0;j<k;j++)
    {
      x=l->data.x;
      y=l->data.y;
      w=l->data.w;
      data.w=m;
      if(isOK(y-1,x)&&w+!map[y-1][x]==m)
      {
        data.y=y-1;
        data.x=x;
        visit[y-1][x]=1;
        i--;
        qPush(q,data);
      }
      if(isOK(y+1,x)&&w+!map[y+1][x]==m)
      {
        data.y=y+1;
        data.x=x;
        visit[y+1][x]=1;
        i--;
        qPush(q,data);
      }
      if(isOK(y,x-1)&&w+!map[y][x-1]==m)
      {
        data.y=y;
        data.x=x-1;
        visit[y][x-1]=1;
        i--;
        qPush(q,data);
      }
      if(isOK(y,x+1)&&w+!map[y][x+1]==m)
      {
        data.y=y;
        data.x=x+1;
        visit[y][x+1]=1;
        i--;
        qPush(q,data);
      }
      l=l->next;
    }
  }
  k=q->count;
  l=q->head;
  for(j=0;j<k;j++)
  {
    x=l->data.x;
    y=l->data.y;
    w=l->data.w;
    if(x==n&&y==n)res=res>w?w:res;
    l=l->next;
  }
  return res;
}
main()
{
  int i,j;
  scanf("%d",&n);
  for(i=1;i<=n;i++)
  {
    for(j=1;j<=n;j++)
    {
      scanf(" %c",&map[i][j]);
      map[i][j]-=48;
    }
  }
  printf("%d",prim());
}
