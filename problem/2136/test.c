typedef struct ant{int pos;char move;}ant;
cmp(ant *a,ant *b){return a->pos>b->pos?1:a->pos<b->pos?-1:0;}
main()
{
  int l,n;
  ant a[100001];
  scanf("%d%d",&n,&l);
  int i,j,k,max=0;
  for(i=0;i<n;i++)
  {
    scanf("%d",&a[i].pos);
    if(a[i].pos>0){a[i].move='R'}
    else {a[i].pos=-a[i].pos;a[i].move='L';}
    j=a[i].move=='L'?a[i].pos:l-a[i].pos;
    max=max<j?j:max;
  }
  qsort(a,n,sizeof(ant),cmp);
  
  printf("%d %d",k+1,max);
}
