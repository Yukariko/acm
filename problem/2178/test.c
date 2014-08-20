#define MAX_QUEUE 1
typedef struct coord{int x,y;} DATA;
typedef struct queue{DATA data;struct queue *next;}queue;
queue *head[MAX_QUEUE],*tail[MAX_QUEUE];
void push(int index,DATA val)
{
  tail[index]->data=val;
  tail[index]->next=(queue *)malloc(sizeof(queue));
  tail[index]=tail[index]->next;
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
  head[index]->next=0;
  tail[index]=head[index];
}
void destroy(int index)
{
  for(;!isEmpty(index);)pop(index);
}

main()
{
  char map[101][101];
  int n,m;
  int i,j;
  init(0);
  scanf("%d%d",&n,&m);
  for(i=1;i<=n;i++)
  {
    for(j=1;j<=m;j++)
    {
      scanf(" %c",&map[i][j]);
      map[i][j]-=48;
    }
  }
  DATA t,pick;
  int s,k,p;
  t.x=1;t.y=1;
  push(0,t);
  k=1;
  for(s=1;;s++)
  {
    for(p=k,k=0;p--;)
    {
      pick=pop(0);
      t.x=t.y=0;
      if(pick.x==n&&pick.y==m){printf("%d",s);return;}
      if(pick.x>1&&map[pick.x-1][pick.y])
      {
        map[pick.x-1][pick.y]=0;
        t.x=pick.x-1;t.y=pick.y;
        push(0,t);
        k++;
      }
      if(pick.x<n&&map[pick.x+1][pick.y])
      {
        map[pick.x+1][pick.y]=0;
        t.x=pick.x+1;t.y=pick.y;
        push(0,t);
        k++;
      }
      if(pick.y>1&&map[pick.x][pick.y-1])
      {
        map[pick.x][pick.y-1]=0;
        t.x=pick.x;t.y=pick.y-1;
        push(0,t);
        k++;
      }
      if(pick.y<m&&map[pick.x][pick.y+1])
      {
        map[pick.x][pick.y+1]=0;
        t.x=pick.x;t.y=pick.y+1;
        push(0,t);
        k++;
      }
    }
  }
}
