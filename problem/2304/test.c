typedef struct column{int pos,height;}column;
cmp(column *a,column *b){return a->pos>b->pos?1:a->pos<b->pos?-1:0;}
main()
{
  column c[1001];
  int n;
  scanf("%d",&n);
  int pos,height;
  int i,max=0;
  for(i=0;i<n;i++)
  {
    scanf("%d%d",&c[i].pos,&c[i].height);
  }
  qsort(c,n,8,cmp);
  int j,k;
  for(i=0;i<n;i++)
  {
    if(max<c[i].height)
    {
      max=c[i].height;
      k=i;
    }
  }
  int s=c[k].height;
  for(i=k;i;)
  {
    max=0;
    for(j=0;j<i;j++)
    {
      max=c[max].height<c[j].height?j:max;
    }
    s+=c[max].height*(c[i].pos-c[max].pos);
    i=max;
  }
  for(i=k;i<n-1;)
  {
    max=n-1;
    for(j=i+1;j<n;j++)
    {
      max=c[max].height<c[j].height?j:max;
    }
    s+=c[max].height*(c[max].pos-c[i].pos);
    i=max;
  }
  printf("%d",s);
}
