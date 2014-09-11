typedef struct pair{int x,y,w;} pair;
cmp(pair *a,pair *b)
{
  return a->x>b->x?1:a->x<b->x?-1:a->y>b->y?1:a->y<b->y?-1:0;
}
pair p[200011];
int pos[100011];
char visit[100011];
int v;
int max;
f(k)
{
  int i,j,sum=0;
  for(i=pos[k];p[i].x==k;i++)
  {
    if(visit[p[i].y]==0)
    {
      visit[p[i].y]=1;
      j=p[i].w+f(p[i].y);
      sum=sum<j?j:sum;
    }
  }
  return sum;
}

main()
{
  int i,j,k;
  int x,y,w;
  scanf("%d",&v);
  for(j=i=0;i<v;i++)
  {
    scanf("%d",&x);
    for(;scanf("%d",&y),y!=-1;)
    {
      scanf("%d",&w);
      p[j].x=x;
      p[j].y=y;
      p[j].w=w;
      j++;
    }
  }
  pos[p[0].x]=0;
  k=p[0].x;
  for(i=0;i<j;i++)
  {
    if(k!=p[i].x)
    {
      k=p[i].x;
      pos[k]=i;
    }
  }
  for(i=1;i<=v;i++)
  {
    memset(visit,0,v+1);
    visit[p[pos[i]].x]=1;
    j=f(p[pos[i]].x);
    max=max<j?j:max;
  }
  printf("%d",max);
}
