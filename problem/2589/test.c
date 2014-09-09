typedef struct pair{int x,y,w;}qData;
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
char map[51][51];
char visit[51][51];
main()
{
  int h,w;
  scanf("%d%d ",&h,&w);
  int i,j;
  for(i=0;i<h;i++)gets(map[i]);
  Queue *q=CreateQueue();
  qData data;
  int max=0,x,y;
  for(i=0;i<h;i++)
  {
    for(j=0;j<w;j++)
    {
      if(map[i][j]=='L')
      {
        memset(visit,0,sizeof(visit));
        data.y=i;
        data.x=j;
        data.w=0;
        qPush(q,data);
        visit[i][j]=1;
        while(q->count)
        {
          data=qPop(q);
          x=data.x;
          y=data.y;
          max=max<data.w?data.w:max;
          data.w++;
          if(y>0&&map[y-1][x]=='L'&&visit[y-1][x]==0)
          {
            data.x=x;
            data.y=y-1;
            visit[data.y][data.x]=1;
            qPush(q,data);
          }
          if(y<h-1&&map[y+1][x]=='L'&&visit[y+1][x]==0)
          {
            data.x=x;
            data.y=y+1;
            visit[data.y][data.x]=1;
            qPush(q,data);
          }
          if(x>0&&map[y][x-1]=='L'&&visit[y][x-1]==0)
          {
            data.x=x-1;
            data.y=y;
            visit[data.y][data.x]=1;
            qPush(q,data);
          }
          if(x<w-1&&map[y][x+1]=='L'&&visit[y][x+1]==0)
          {
            data.x=x+1;
            data.y=y;
            visit[data.y][data.x]=1;
            qPush(q,data);
          }
        }
      }
    }
  }
  printf("%d",max);
}
