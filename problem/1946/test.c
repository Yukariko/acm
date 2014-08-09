typedef struct man{int no,data;}man;
int t;
int n;
int i,j,k,max;
man a[100001];
int b[100001];
cmp(man *p,man *q)
{
  if(p->data > q->data)
    return 1;
  if(p->data < q->data)
    return -1;
  return 0;
}

main()
{
  for(scanf("%d",&t);t--;)
  {
    scanf("%d",&n);
    for(i=0;i<n;i++)
    {
      a[i].no=i;
      scanf("%d%d",&a[i].data,&b[i]);
    }
    qsort(a,n,sizeof(man),cmp);
    max=100001;
    for(k=i=0;i<n;++i)
    {
      if(max>b[a[i].no])
      {
        max=b[a[i].no];
        ++k;
      }
    }
    printf("%d\n",k);
  }
}
