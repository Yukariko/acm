typedef struct pair{int x,y,max,min;} qData;
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
qData make_pair(x,y,max,min)
{
  qData data;
  data.x=x;
  data.y=y;
  data.max=max;
  data.min=min;
  return data;
}
#define MAX(a,b) (a>b?a:b)
#define MIN(a,b) (a>b?b:a)
int n;
int map[101][101];
int check[101][101][2];
isOK(x,y)
{
  return x<0||y<0||x>=n||y>=n?0:1;
}
int d[2][4]={
  {1,-1,0,0},
  {0,0,1,-1}
};
main()
{
  int i,j,k;
  scanf("%d",&n);
  for(i=0;i<n;i++)
  {
    for(j=0;j<n;j++)
    {
      scanf("%d",&map[i][j]);
      check[i][j][0]=0;
      check[i][j][1]=201;
    }
  }
  Queue *q=CreateQueue();
  qPush(q,make_pair(0,0,map[0][0],map[0][0]));
  check[0][0][0]=check[0][0][1]=map[0][0];
  
  qData data;
  for(;q->count;)
  {
    data=qPop(q);
    for(i=0;i<4;i++)
    {
      int x,y;
      x=data.x+d[0][i];
      y=data.y+d[1][i];
      if(isOK(x,y)==0)continue;
      j=MAX(data.max,map[x][y]);
      k=MIN(data.min,map[x][y]);
      if(j-k<check[x][y][1]-check[x][y][0])
      {
        check[x][y][0]=k;
        check[x][y][1]=j;
        qPush(q,make_pair(x,y,j,k));
      }
    }
  }
  printf("%d",check[n-1][n-1][1]-check[n-1][n-1][0]);
}
