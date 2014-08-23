#define MAX_QUEUE 1
typedef int DATA;
typedef struct queue{DATA data;struct queue *next;}queue;
queue *head[MAX_QUEUE],*tail[MAX_QUEUE];
void push(int index,DATA val)
{
  tail[index]->data=val;
  tail[index]->next=(queue *)malloc(sizeof(queue));
  tail[index]=tail[index]->next;
  tail[index]->next=0;
}
void init(int index)
{
  head[index]=(queue *)malloc(sizeof(queue));
  head[index]->next=0;
  tail[index]=head[index];
}
main()
{
  int n,M;
  queue *q,*qh;
  init(0);
  scanf("%d%d",&n,&M);
  int i,j,k;
  for(i=1;i<=n;i++)push(0,i);
  for(q=head[0];q->next->next;q=q->next);
  qh=q->next;
  q->next=head[0];
  q=head[0];
  printf("<");
  for(j=n;j--;)
  {
    for(k=M;--k;)
    {
      qh=q;
      q=q->next;
    }
    i=q->data;
    qh->next=q->next;
    q=q->next;

    if(j!=0)printf("%d, ",i);
    else printf("%d",i);

  }
  printf(">");
}

