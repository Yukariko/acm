typedef struct point{int x,y;}point;
cmp(point *a,point *b){return a->x>b->x?1:a->x<b->x?-1:a->y>b->y?1:a->y<b->y?-1:0;}
cmp2(point *a,point *b){return a->y>b->y?1:a->y<b->y?-1:a->x>b->x?1:a->x<b->x?-1:0;}
main()
{
  int n;
  scanf("%d",&n);
  point p[100001];
  int i,j,t;
  for(i=0;i<n;i++){scanf("%d%d",&p[i].x,&p[i].y);}
  int min=987654321;
  qsort(p,n,8,cmp);
  for(i=0;i<n;i++)
  {
    for(j=i+1;j<n;j++)
    {
      t=(p[i].x-p[j].x)*(p[i].x-p[j].x)+(p[i].y-p[j].y)*(p[i].y-p[j].y);
      if(t<min)
      {
        min=t;
      }
      else break;
    }
  }
  qsort(p,n,8,cmp2);
  for(i=0;i<n;i++)
  {
    for(j=i+1;j<n;j++)
    {
      t=(p[i].x-p[j].x)*(p[i].x-p[j].x)+(p[i].y-p[j].y)*(p[i].y-p[j].y);
      if(t<min)
      {
        min=t;
      }
      else break;
    }
  }
  printf("%d",min);
}
