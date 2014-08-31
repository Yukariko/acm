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
void init(int index)
{
  head[index]=(queue *)malloc(sizeof(queue));
  head[index]->next=0;
  tail[index]=head[index];
}
int point[101][101];
char visit[101][101];
char map[101][101];
int n,m;
f(i,j,s)
{
  if(map[i][j]==0)return;
  if(visit[i][j])return;
  visit[i][j]=1;
  point[i][j]=s;
  if(i<m&&map[i+1][j])f(i+1,j,s);
  if(i>1&&map[i-1][j])f(i-1,j,s);
  if(j<n&&map[i][j+1])f(i,j+1,s);
  if(j>1&&map[i][j-1])f(i,j-1,s);
}
clear()
{
  int i,j;
  for(i=1;i<=m;i++)for(j=1;j<=n;j++)visit[i][j]=0;
}
#define min(a,b) (a>b?b:a)
main()
{
  char mask[101][101]={};
  int i,j;
  init(0);
  scanf("%d%d ",&n,&m);
  for(i=1;i<=m;i++)
  {
    for(j=1;j<=n;j++)
    {
      scanf(" %c",&map[i][j]);
      map[i][j]-=48;
      map[i][j]=!map[i][j];
      point[i][j]=30000;
    }
  }
  DATA t,pick;
  int s,k,p,w;
  t.x=1;t.y=1;
  push(0,t);
  point[1][1]=0;
  for(k=1;k;)
  {
    for(p=k,k=0;p--;)
    {
      pick=pop(0);
      if(pick.x<m)
      {
        if(map[pick.x+1][pick.y])
        {
          w=0;
        }
        else
        {
          w=1;
        }
        if(point[pick.x+1][pick.y]>point[pick.x][pick.y]+w)
        {
          point[pick.x+1][pick.y]=point[pick.x][pick.y]+w;
          if(w==0)
          {
            clear();
            f(pick.x+1,pick.y,point[pick.x+1][pick.y]);
          }
        }
        t.x=pick.x+1;t.y=pick.y;
        if(!mask[pick.x+1][pick.y]){push(0,t);k++;}
        mask[pick.x+1][pick.y]=1;
      }
      if(pick.y<n)
      {
        if(map[pick.x][pick.y+1])
        {
          w=0;
        }
        else
        {
          w=1;
        }
        if(point[pick.x][pick.y+1]>point[pick.x][pick.y]+w)
        {
          point[pick.x][pick.y+1]=point[pick.x][pick.y]+w;
          if(w==0)
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
  printf("%d",point[m][n]);
}
