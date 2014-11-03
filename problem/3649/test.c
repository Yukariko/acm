cmp(int *p,int *q){return *p>*q?1:*p<*q?-1:0;}
int a[1000001];
main()
{
  int X,N;
  int i;
  for(;~scanf("%d",&X);)
  {
    scanf("%d",&N);
    for(i=0;i<N;scanf("%d",a+i++));
    
    X *= 10000000;
    if(X > 200000000 || X <= 0){puts("danger");continue;}
    
    qsort(a,N,4,cmp);
    
    int p=-1,q;
    for(i=0;i<N && a[i] <= X - a[i];i++)
    {
      int t = X - a[i];
      int *tp = bsearch(&t, a+i+1, N-i-1, 4, cmp);
      if(tp)
      {
        p = a[i];
        q = *tp;
        break;
      }
    }
    if(p==-1)puts("danger");
    else printf("yes %d %d\n",p,q);
  }
}
