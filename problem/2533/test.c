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

Min(a,b){return a>b?b:a;}

Queue *tree[1000001];
int N;
int dp[1000001][2];
char visit[1000001];
f(pos,isEarly)
{
  if(dp[pos][isEarly]) return dp[pos][isEarly];
  LinkedList *tmp = tree[pos]->head;
  int early=1,notEarly=0;
  for(int i=0;i<tree[pos]->count;i++)
  {
    if(visit[tmp->data] == 0)
    {
      visit[tmp->data] = 1;
      early += f(tmp->data,1);
      if(isEarly == 1)
      {
        notEarly += f(tmp->data,0);
      }
      visit[tmp->data] = 0;
    }
    tmp = tmp->next;
  }
  return dp[pos][isEarly] = isEarly? Min(early,notEarly) : early;
}
main()
{
  int p,q,i;
  scanf("%d",&N);
  for(i=0;i<=N;i++)tree[i] = CreateQueue();
  for(i=1;i<N;i++)
  {
    scanf("%d%d",&p,&q);
    qPush(tree[p],q);
    qPush(tree[q],p);
  }
  visit[1]=1;
  printf("%d",Min(f(1,0),f(1,1)));
}
