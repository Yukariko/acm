typedef struct jul{long long v;int n;}jul;
char b[32001][32001]={0};
cmp(jul *p, jul *q)
{
  return b[p->n][q->n]?b[p->n][q->n]:p->n-q->n;
//  return a->v+-b->v?a->v-b->v:a->n-b->n;
//return a->v+a->n-b->v-b->n;
}
main()
{
  int n,m;
  jul a[100001];
  int i,j,x,y;
  scanf("%d%d",&n,&m);
  for(i=1;i<=n;i++){a[i].v=0;a[i].n=i;}
  for(i=1;m--;i++)
  {
    scanf("%d%d",&x,&y);
    b[x][y]=-1;
   // b[y][x]=1;
    if(a[x].v>=a[y].v){a[x].v=0;a[y].v=a[x].v+n;}
  }
  
  qsort(a+1,n,sizeof(jul),cmp);
  for(j=1;j<=n;j++)
  {
    if(a[j].v == -1)
    for(x=i=j;i<=n;i++)
    {
      if(a[j].n>a[i].n)x++;
    }
//    b[x]=a[j].n;
    printf("%d ",a[j].n);
  }
}
