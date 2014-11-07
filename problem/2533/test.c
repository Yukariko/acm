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

Queue *tree[1000001];
int N;
int dp[1000001];
char visit[1000001];
f(pos,needAlly)
{
  if(dp[pos]) return dp[pos];
  LinkedList *tmp = tree[pos]->head;
  int min,k,res=0;
  for(int i=0;i<tree[pos]->count;i++)
  {
    min = 1+f(tmp->data,0);
    if(needAlly == 0)
    {
      k = f(tmp->data,1);
      min = min > k? k: min;
    }
    if(pos==1)printf("%d %d\n",needAlly,min);
    res += min;
    tmp = tmp->next; 
  }
  return dp[pos] = res;
}
main()
{
  int p,q;
  int i;
  scanf("%d",&N);
  for(i=0;i<=N;i++)tree[i] = CreateQueue();
  for(i=1;i<N;i++)
  {
    scanf("%d%d",&p,&q);
    qPush(tree[p],q);
    visit[q]=1;
  }
  
  int root;
  for(i=1;i<=N;i++)if(visit[i]==0)break;
  root=i;
  qPush(tree[0],root);
  p=f(0,0);
  printf("%d",p);
}
