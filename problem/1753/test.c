#define MAX_STACK 20001
typedef struct{int v;int w;} DATA;
typedef struct stack{DATA data;struct stack *next;}stack;
stack *head[MAX_STACK];
void push(int index,DATA val)
{
  stack *p=head[index];
  head[index]=(stack *)malloc(sizeof(stack));
  head[index]->data=val;
  head[index]->next=p;
}

void init(int index)
{
  head[index]=(stack *)malloc(sizeof(stack));
  head[index]->next=0;
}

int d[20001];
int check[20001];
int v,e,k,s;
extraMin()
{
  int i,min=65535,res=0,j=0,t=0,k;
  for(i=1;i<=s;++i)
  {
    k=check[i];
    if(head[k])
    {
      if(d[k]<min)
      {
        min=d[k];
        res=k;
        t=i;
      }
    }
    else if(++j>=s)break;
  }
  if(t){check[t]=check[s];}
  s--;
  return res;
}
dijkstra()
{
  int i,j;
  int u;
  for(i=1;i<=v;++i)d[i]=65535;
  d[k]=0;
  for(s=v;s;)
  {
    u=extraMin();
    stack *p;
    for(p=head[u];p;p=p->next)
    {
      if(head[p->data.v]&&d[p->data.v]>d[u]+p->data.w)
      {
        d[p->data.v]=d[u]+p->data.w;
      }
    }
    head[u]=0;
  }
  for(i=1;i<=v;++i)
  {
    if(d[i]==65535)puts("INF");
    else printf("%d\n",d[i]);
  }
}
main()
{

  int i,j;
  scanf("%d%d%d",&v,&e,&k);
  DATA t;
  for(i=1;i<=v;i++){init(i);check[i]=i;}
  for(i=0;i<e;i++)
  {
    scanf("%d%d%d",&j,&t.v,&t.w);
    push(j,t);
  }
  dijkstra();
}
