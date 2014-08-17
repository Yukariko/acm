#define MAX_QUEUE 1
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
  head[index]=head[index]->next;
  free(p);
}
void init(int index)
{
  head[index]=(queue *)malloc(sizeof(queue));
  head[index]->data=0;
  head[index]->next=0;
  tail[index]=head[index];
}
void destroy(int index)
{
  for(;head[index];)pop(index);
}
typedef struct BATTLESHIP{int sx,sy,ex,ey,w;}BATTLESHIP;
main()
{
  int t;
  int n,k,l;
  int point,wh; 
  int i,j,temp;
  BATTLESHIP ship[100001];
  queue *p,*ph;
  for(scanf("%d",&t);t--;)
  {
    scanf("%d%d%d",&n,&k,&l);
    init(0);
    push(0,0);
    for(i=0;i<k;i++)
    {
      scanf("%d%d%d%d%d",&ship[i].sx,&ship[i].sy,&ship[i].ex,&ship[i].ey,&ship[i].w);
      if(ship[i].sx > ship[i].ex){temp=ship[i].sx;ship[i].sx=ship[i].ex;ship[i].ex=temp;}
      if(ship[i].sy > ship[i].ey){temp=ship[i].sy;ship[i].sy=ship[i].ey;ship[i].ey=temp;}
      push(0,i);
    }
    for(i=0;i<l;i++)
    {
      scanf("%d%d",&point,&wh);
      int max=0;
      ph=head[0];
      if(wh==0)
      {
        for(p=head[0]->next;p;ph=p,p=p->next)
        {
          j=p->data;
          if(ship[j].sy<=point&&point<=ship[j].ey)
          {
            max=max<ship[j].w?ship[j].w:max;
            ph->next=p->next;
            free(p);
            p=ph;
          }
        }
      }
      else
      {
        for(p=head[0]->next;p;ph=p,p=p->next)
        {
          j=p->data;
          if(ship[j].sx<=point&&point<=ship[j].ex)
          {
            max=max<ship[j].w?ship[j].w:max;
            ph->next=p->next;
            free(p);
            p=ph;
          }
        }        
      }
      printf("%d\n",max);
    }
    destroy(0);
  }
}
