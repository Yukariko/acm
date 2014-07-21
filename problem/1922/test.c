typedef int DATA;
typedef struct queue{DATA data;struct queue *next;}queue;
queue *head,*tail;
push(DATA val)
{
  tail->data=val;
  tail->next=(queue *)malloc(sizeof(queue));
  tail=tail->next;
  tail->data=0;
  tail->next=0;
}
DATA pop()
{
  queue *p=head;
  DATA result=head->data;
  head=head->next;
  free(p);
  return result;
}
int isEmpty()
{
  return !head;
}
void init()
{
  head=(queue *)malloc(sizeof(queue));
  head->data=0;
  head->next=0;
  tail=head;
}
queue *find(DATA val)
{
  queue *p=head;
  for(;p;p=p->next)if(p->data==val)return p;
  return 0;
}
int network[1001][1001];
int visited[1001];
int N,M;
int i;
prim()
{
  int i,j,s,m;
  int x,y;
  int result=0;
  queue *p;
  init();
  visited[1]=1;
  s=1;
  push(1);
  for(;;)
  {
    m=987654321;
    for(p=head;p;p=p->next)
    {
      for(i=1;i<=N;i++)
      {
        if(!visited[i]&&network[p->data][i]&&m>network[p->data][i])
        {
          m=network[p->data][i];
          x=i;
          y=p->data;
        }
      }
    }
    result+=network[x][y];
    visited[x]=1;
    s++;
    if(!find(x))push(x);
    if(s==N)break;
  } 
  return result;
}
main(x,y,m)
{
  for(scanf("%d%d",&N,&M);i<M;i++){scanf("%d%d%d",&x,&y,&m);network[x][y]=m;network[y][x]=m;}
  printf("%d",prim());
}
