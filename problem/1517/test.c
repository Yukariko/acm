cmp(int *a,int *b)
{
  return *a>*b?1:*a<*b?-1:0;
}
  int a[500001];
  int b[500001];
  int warp[500001];
  char ck[500001];
main()
{

  int i,n,t,s=0,j;
  scanf("%d",&n);
  for(i=0;i<n;i++){scanf("%d",a+i);b[i]=a[i];}
  qsort(a,n,4,cmp);
  for(i=0;i<n;i++)
  {
    t=(int *)bsearch(&b[i],a,n,4,cmp)-a;
    t+=1;
    if(!warp[t])
    {
    	for(j=t;a[j]==b[i];j++);
        warp[t]=j-1;   
    }
    t=warp[t];
    s+=abs(t-i)-ck[t];
    ck[t]=1;
    ck[i]=1;
  }
  printf("%d\n",s);
}

