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
int r,c;
isOK(i,j)
{
  return i<0||i>=r||j<0||j>=c||map[i][j]!='.'?0:1;
}
isOK2(i,j)
{
  if(map[i][j]=='D')return 1;
  return i<0||i>=r||j<0||j>=c||visit[i][j]||map[i][j]!='.'?0:1;
}
f()
{
  int i,j;
  for(i=0;i<r;i++)
  {
    for(j=0;j<c;j++)
    {
      if(map[i][j]=='*')
      {
        if(isOK(i-1,j))map[i-1][j]=1;
        if(isOK(i+1,j))map[i+1][j]=1;
        if(isOK(i,j-1))map[i][j-1]=1;
        if(isOK(i,j+1))map[i][j+1]=1;
      }
    }
  }
  for(i=0;i<r;i++)
  {
    for(j=0;j<c;j++)
    {
      if(map[i][j]==1)
      {
        map[i][j]='*';
      }
    }
  }
}
int d[2][4]={
  {1,-1,0,0},
  {0,0,1,-1}
};
main()
{
  scanf("%d%d ",&r,&c);
  int i,j;
  for(i=0;i<r;i++)gets(map[i]);
  int s;
  int dx,dy,sx,sy;
  for(i=0;i<r;i++)
  {
    for(j=0;j<c;j++)
    {
      if(map[i][j]=='D'){dx=i;dy=j;}
      if(map[i][j]=='S'){sx=i;sy=j;}
    }
  }
  Queue *q=CreateQueue();
  qData data;
  data.x=sx;
  data.y=sy;
  qPush(q,data);
  visit[sx][sy]=1;
  int x,y,sel=-1;
  for(s=1;;s++)
  {
    int count=q->count;
    int j=0;
    f();
    for(;count--;)
    {
      data=qPop(q);
      x=data.x;
      y=data.y;
      for(i=0;i<4;i++)
      {
        if(isOK2(x+d[0][i],y+d[1][i]))
        {
          data.x=x+d[0][i];
          data.y=y+d[1][i];
          visit[data.x][data.y]=1;
          qPush(q,data);
          j=1;
          if(data.x==dx&&data.y==dy)return printf("%d",s),0;
        }
      }
    }
    if(j==0)break;
  }
  puts("KAKTUS");
}
