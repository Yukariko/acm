#include<malloc.h>
#include<stdio.h>
#include<memory.h>
#include<stdlib.h>
#define MAX_QUEUE 3
typedef int DATA;
typedef struct queue{DATA data;struct queue *next;}queue;
queue *head[MAX_QUEUE],*tail[MAX_QUEUE];
void push(int index,DATA val)
{
  tail[index]->data=val;
  tail[index]->next=(queue *)malloc(sizeof(queue));
  tail[index]=tail[index]->next;
  tail[index]->data=0;
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
  return !(head[index]->data);
}
void init(int index)
{
  head[index]=(queue *)malloc(sizeof(queue));
  head[index]->data=0;
  head[index]->next=0;
  tail[index]=head[index];
}
int vec[1001][1001];
int visited[1001];
int n,m,v;
int x,y;
dfs(s)
{
  int i;
  for(i=1;i<=n;i++)
  {
    if(!visited[i]&&vec[s][i])
    {
      printf("%d ",i);
      visited[i]=1;
      dfs(i);
    }
  }
}
bfs()
{
  int i,j;
  memset(visited,0,1001*4);
  init(0);
  push(0,v);
  visited[v]=1;
  printf("%d ",v);  
  for(;!isEmpty(0);)
  {
    i=pop(0);

    for(j=1;j<=n;j++)
    {
      if(!visited[j]&&vec[i][j]){visited[j]=1;push(0,j);printf("%d ",j);}
    }
  }
}

main()
{
  for(scanf("%d%d%d",&n,&m,&v);m--;)
  {
    scanf("%d%d",&x,&y);
    vec[x][y]=1;vec[y][x]=1;
  }
  printf("%d ",v);visited[v]=1;dfs(v);puts("");bfs();
}
