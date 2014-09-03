typedef struct point{int x,y;}point;
cmp(point *a,point *b){return a->x>b->x?1:a->x<b->x?-1:0;}
main()
{
  int t;
  point p[10001];
  for(scanf("%d",&t);t--;)
  {
    int n,k;
    scanf("%d%d",&n,&k);
    int i;
    for(i=0;i<n;i++)
    {
      scanf("%d%d",&p[i].x,&p[i].y);
    }
    
  }
}
