#define MAX_QUEUE 1
typedef struct coord{int x,y,w;} DATA;
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
int point[51][51];
char visit[51][51];
char map[51][51];
char mask[51][51];
int n;
f(i,j,s)
{
  if(map[i][j]==0)return;
  if(visit[i][j])return;
  visit[i][j]=1;
  point[i][j]=s;
  if(i<n&&map[i+1][j])f(i+1,j,s);
  if(i>1&&map[i-1][j])f(i-1,j,s);
  if(j<n&&map[i][j+1])f(i,j+1,s);
  if(j>1&&map[i][j-1])f(i,j-1,s);
}
clear()
{
  int i,j;
  for(i=1;i<=n;i++)for(j=1;j<=n;j++)visit[i][j]=0;
}
#define min(a,b) (a>b?b:a)
main()
{
  int i,j;
  init(0);
  scanf("%d",&n);
  for(i=1;i<=n;i++)
  {
    for(j=1;j<=n;j++)
    {
      scanf(" %c",&map[i][j]);
      map[i][j]-=48;
      point[i][j]=10000;
    }
  }
  DATA t,pick;
  int s,k,p;
  t.x=1;t.y=1;t.w=0;
  push(0,t);
  point[1][1]=0;
  for(k=1;k;)
  {
    for(p=k,k=0;p--;)
    {
      pick=pop(0);
      t.x=t.y=t.w=0;
      if(pick.x<n)
      {
        if(map[pick.x+1][pick.y])
        {
          t.w=0;
        }
        else
        {
          t.w=1;
        }
        if(point[pick.x+1][pick.y]>point[pick.x][pick.y]+t.w)
        {
          point[pick.x+1][pick.y]=point[pick.x][pick.y]+t.w;
          if(t.w==0)
          {
            clear();
            f(pick.x+1,pick.y,point[pick.x+1][pick.y]);
          }
        }
        t.x=pick.x+1;t.y=pick.y;t.w=pick.w+t.w;
        if(!mask[pick.x+1][pick.y]){push(0,t);k++;}
        mask[pick.x+1][pick.y]=1;
      }
      if(pick.y<n)
      {
        
        if(map[pick.x][pick.y+1])
        {
          t.w=0;
        }
        else
        {
          t.w=1;
        }
        if(point[pick.x][pick.y+1]>point[pick.x][pick.y]+t.w)
        {
          point[pick.x][pick.y+1]=point[pick.x][pick.y]+t.w;
          if(t.w==0)
          {
            clear();
            f(pick.x,pick.y+1,point[pick.x][pick.y+1]);
          }
        }
        t.x=pick.x;t.y=pick.y+1;
        if(!mask[pick.x][pick.y+1]){push(0,t);k++;}
        mask[pick.x][pick.y+1]=1;
      }
    }
  }
/*  for(i=1;i<=n;i++)
  {
    for(j=1;j<=n;j++)
    {
      printf("%2d ",point[i][j]);
    }
    puts("");
  }*/
  printf("%d",point[n][n]);
}
