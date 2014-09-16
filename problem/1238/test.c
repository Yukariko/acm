typedef struct edge{int x,y,w;}Edge;
cmp(Edge *a,Edge *b){return a->w>b->w?1:a->w<b->w?-1:0;}
int *jump;
int *r;
find(n)
{
  if(n==jump[n])return n;
  return p[n]=find(p[n]);
}
merge(x,y)
{
  x=find(x);
  y=find(y);
  if(r[x]<r[y])p[x]=y;
  else
  {
    p[y]=x;
    if(r[x]==r[y])r[x]++;
  }
}
kruskal(Edge *edge, int n, int m)
{
  int i;
  long long res=0;
  
  qsort(edge,m,sizeof(Edge),cmp);
  jump=malloc(sizeof(int)*n);
  r=malloc(sizeof(int)*m);
  
  for(i=1;i<=n;i++)jump[i]=i;
  
  for(i=0;i<m;i++)
  {
    int x=edge[i].x,y=edge[i].y;
    if(find(x)!=find(y))
    {
      merge(x,y);
      res+=edge[i].w;
    }
  }
  return res;
}
main()
{
  Edge p[10001];
  int n,m,k;
  scanf("%d%d%d",&n,&m,&k);
  int i;
  for(i=0;i<m;i++)scanf("%d%d%d",&p[i].x,&p[i].y,&p[i].w);
}
