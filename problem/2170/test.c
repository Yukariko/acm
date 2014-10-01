typedef struct line{int p,q;}LINE;
cmp(LINE *a,LINE *b){return a->p>b->p?1:a->p<b->p?-1:a->q>b->q?1:a->q<b->q?-1:0;}
LINE l[1000001];
main()
{
  int n;
  scanf("%d",&n);
  for(int i=0;i<n;i++)
  {
    scanf("%d%d",&l[i].p,&l[i].q);
    if(l[i].p>l[i].q)
    {
      int t=l[i].p;
      l[i].p=l[i].q;
      l[i].q=t;
    }
  }
  qsort(l,n,8,cmp);
  long long s=l[0].q-l[0].p;
  int min=l[0].q;
  for(int i=1;i<n;i++)
  {
    if(l[i].q>min)
    {
      if(l[i].p>l[i-1].q)min=l[i].p;
      s+=l[i].q - min;
      min=l[i].q;
    }
  }
  printf("%lld",s);
}
