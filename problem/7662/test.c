#define MAX_QUEUE 1
typedef int DATA;
typedef struct queue{DATA data;struct queue *next;struct queue *prev;}queue;
queue *head[MAX_QUEUE],*tail[MAX_QUEUE];
void push(int index,DATA val)
{
  tail[index]->next=(queue *)malloc(sizeof(queue));
  tail[index]->next->prev=tail[index];
  tail[index]=tail[index]->next;
  tail[index]->data=val;
  tail[index]->next=0;
}
void put(int index,queue *q,DATA val)
{
  queue *t = q->prev;
  q->prev=(queue *)malloc(sizeof(queue));
  q->prev->data=val;
  if(t)
  {
    t->next=q->prev;
    q->prev->prev=t;
  }
  else q->prev->prev=0;
  if(q==head[index])head[index]=q->prev;

  q->prev->next=q;
}
DATA pop(int index)
{
  queue *p=head[index];
  head[index]=head[index]->next;
  free(p);
}
DATA pick(queue *parent,queue *child)
{
  DATA res = child->data;
  parent->next=child->next;
  free(child);
  return res;
}
void init(int index)
{
  head[index]=(queue *)malloc(sizeof(queue));
  head[index]->data=0;
  head[index]->next=0;
  head[index]->prev=0;
  tail[index]=head[index];
}
void destroy(int index)
{
  for(;head[index];)pop(index);
}
main()
{
  int t;
  for(scanf("%d",&t);t--;)
  {

    init(0);
    char cmd;
    int k,val,arrNull=0;
    queue *q,*qp;
    for(scanf("%d",&k);k--;)
    {
      scanf(" %c %d",&cmd,&val);
      if(cmd=='I')
      {
        push(0,val);
        arrNull=1;
      }
      else if (cmd=='D'&&arrNull)
      {
        if(head[0]==tail[0]){arrNull=0;continue;}
        if(val == -1)
        {
          queue *min=tail[0];
          for(q=head[0]->next;q;q=q->next)
          {
            min=min->data>q->data?q:min;
          }
          min->prev->next=min->next;
          if(min->next)min->next->prev=min->prev;
          if(min==tail[0])tail[0]=min->prev;
          free(min);
        }
        else
        {
          queue *max=tail[0];
          for(q=head[0]->next;q;q=q->next)
          {
            max=max->data<q->data?q:max;
          }
          max->prev->next=max->next;
          if(max->next)max->next->prev=max->prev;
          if(max==tail[0])tail[0]=max->prev;
          free(max);
        }
      }
    }
    queue *min=tail[0],*max=tail[0];
    for(q=head[0]->next;q;q=q->next)
    {
      min=min->data>q->data?q:min;
      max=max->data<q->data?q:max;
    }
    
    if(head[0]!=tail[0])printf("%d %d\n",max->data,min->data);
    else puts("EMPTY");
    destroy(0);
  }
}
