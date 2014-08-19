cmp(int *a,int *b)
{
  return *a>*b?1:*a<*b?-1:0;
}
  int a[500001];
  int b[500001];
  int warp[500001];
main()
{

  int i,n,t,m=1,j;
  scanf("%d",&n);
  for(i=0;i<n;i++){scanf("%d",a+i);b[i]=a[i];}
  qsort(a,n,4,cmp);
  for(i=0;i<n;i++)
  {
    t=(int *)bsearch(&b[i],a,n,4,cmp)-a;
    if(!warp[t])
    {
    	for(j=t;a[j]==b[i];j++);
        warp[t]=j-1;   
    }
    t=warp[t]-1;
    m=m<i-t?i-t:m;
  }
  printf("%d\n",m);
}

