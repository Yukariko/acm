typedef struct ant{int pos;char move;}ant;
cmp(ant *a,ant *b){return a->pos>b->pos?1:a->pos<b->pos?-1:0;}
main()
{
  int l,t;
  int n;
  scanf("%d%d",&l,&t);
  scanf("%d",&n);
  ant a[70001];
  int i;
  for(i=0;i<n;i++)
  {
    scanf("%d %c",&a[i].pos,&a[i].move);
  }
  int p,q;
  for(i=0;i<n;i++)
  {
    int k=t;
    if(a[i].move=='L')
    {
      if(k>=a[i].pos)
      {
        k-=a[i].pos;
        p=k/l;
        q=k%l;
        a[i].pos=p%2?l-q:q;
      }
      else
      {
        a[i].pos-=k;
      }
    }
    else
    {
      if(k>=l-a[i].pos)
      {
        k-=l-a[i].pos;
        p=k/l;
        q=k%l;
        a[i].pos=p%2?q:l-q;
      }
      else
      {
        a[i].pos+=k;
      }
    }
  }
  qsort(a,n,sizeof(ant),cmp);
  for(i=0;i<n;i++)printf("%d ",a[i].pos);
}

