typedef struct range{int a,b;}range;
cmp(range *p,range *q)
{
  int i,j;
  i=p->b-p->a;
  j=q->b-q->a;
  return i>j?1:i<j?-1:0;
}
main()
{
  int t;
  range r[1001];
  for(scanf("%d",&t);t--;)
  {
    int map[1001]={};
    int n,m;
    scanf("%d%d",&n,&m);
    int i,j;
    for(i=0;i<m;i++)
    {
      scanf("%d%d",&r[i].a,&r[i].b);
      for(j=r[i].a;j<=r[i].b;j++)map[j]++;
    }
    qsort(r,m,8,cmp);
    int s=0;
    for(i=0;i<m;i++)
    {
      int min=1001,pos=-1;
      for(j=r[i].a;j<=r[i].b;j++)
      {
        if(min>map[j])
        {
          min=map[j];
          pos=j;
        }
      }
      if(pos!=-1)
      {
        map[pos]=1001;
        s++;
      }
    }
    printf("%d\n",s);
  }
}
