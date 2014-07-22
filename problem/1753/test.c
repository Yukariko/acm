#define MAX_QUEUE 20001
typedef struct{int start;int end;int m;} DATA;
typedef struct queue{DATA data;struct queue *next;}queue;
queue *head[MAX_QUEUE],*tail[MAX_QUEUE];
void push(int index,DATA val)
{
  tail[index]->data=val;
  tail[index]->next=(queue *)malloc(sizeof(queue));
  tail[index]=tail[index]->next;
  memset(&tail[index]->data,0,sizeof(DATA));
  tail[index]->next=0;
}
DATA pop(int index)
{
  queue *p=head[index];
  DATA result=head[index]->data;
  head[index]=head[index]->next;
  free(p);
  return result;
}
int isEmpty(int index)
{
  return !head[index];
}
void init(int index)
{
  head[index]=(queue *)malloc(sizeof(queue));
  memset(&head[index]->data,0,sizeof(DATA));
  head[index]->next=0;
  tail[index]=head[index];
}
void destroy(int index)
{
  for(;!isEmpty(index);)pop(index);
}
int find(int index,int val)
{
  queue *p=head[index];
  for(;p;p=p->next)if(p->data.end==val)return p->data.m;
  return -1;
}
int visited[20001];
int N,M,K;
int i;
prim()
{
  int i,j,s,m;
  int x,y;
  int result=0;
  DATA t;
  queue *p,*q;
  init(0);
  visited[K]=1;
  t.start = k;
  t.end = K;
  t.m = 0;
  s=1;
  push(0,t);
  for(;s<N;s++)
  {
    m=98765;
    for(p=head[0];p;p=p->next)
    {
      j=p->data.end;
      for(q=head[j];q;q=q->next)
      {
        i=q->data.end;
        if(!visited[i]&&m>q->data.m)
        {
          m=q->data.m;
          x=i;
          y=j;
        }
      }
    }
    t.start=y;
    t.end=x;
    t.m=m;
    visited[x]=1;
    push(0,t);
  }
  for(i=1;i<=N;i++)
  {
    m=find(0,i);
    if(m>=0)printf("%d\n",m);
    else puts("INF");
  }
  return result;
}
main(x,y,m)
{
  scanf("%d%d%d",&N,&M,&K);
  DATA t;
  for(i=1;i<=N;i++)init(i);
  for(i=1;i<=M;i++){scanf("%d%d%d",&x,&y,&m);t.start=x;t.end=y;t.m=m;push(x,t);}
  prim();
}
