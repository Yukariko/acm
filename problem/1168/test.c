typedef int DATA;
typedef struct queue{DATA data;struct queue *left,*right;}queue;
queue *head,*tail;
void push(DATA val)
{
  tail->data=val;
  tail->right=(queue *)malloc(sizeof(queue));
  tail->right->left=tail;
  tail=tail->right;
  tail->right=0;
}
void init()
{
  head=(queue *)malloc(sizeof(queue));
  head->right=head->left=0;
  tail=head;
}
main()
{
  int n,M;
  queue *q,*qh;
  init();
  scanf("%d%d",&n,&M);
  int i,j,k;
  for(i=1;i<=n;i++)push(i);
  for(q=head;q->right->right;q=q->right);
  qh=q->right;
  q->right=head;
  head->left=q;
  q=head;
  printf("<");
  if(n/2<M)
  {
    for(j=n;j--;)
    {
      for(k=M;--k;)
      {
        qh=q;
        q=q->right;
      }
      i=q->data;
      qh->right=q->right;
      q=q->right;
  
      if(j!=0)printf("%d, ",i);
      else printf("%d",i);
    }
  }
  else
  {
    M=n-M;
    q=q->left;
    for(j=n;j--;)
    {
      for(k=M;--k;)
      {
        qh=q;
        q=q->left;
      }
      i=q->data;
      qh->left=q->left;
      q=q->left;
  
      if(j!=0)printf("%d, ",i);
      else printf("%d",i);
    }
  }
  printf(">");
}

