typedef struct time{int x,y;}time;
cmp(time *a,time *b){return a->y<b->y?-1:a->y>b->y?1:a->x<b->x?-1:a->x > b->x? 1:0;}
main()
{
  int n;
  time t[100001];
  scanf("%d",&n);
  int i,j;
  for(i=0;i<n;i++)scanf("%d%d",&t[i].x,&t[i].y);
  qsort(t,n,8,cmp);
  int m=t[0].y,s=1;
  for(i=1;i<n;i++)
  {
    if(t[i].x>=m){m=t[i].y;s++;}
  }
  printf("%d",s);
}
