#define MIN(a,b) (a>b?b:a)
cmp(int *a,int *b){return *a>*b?1:*a<*b?-1:0;}
main()
{
  int n,m;
  scanf("%d%d",&n,&m);
  int i,j,max=0,maxPrice=0;
  int a[1001];
  for(i=0;i<m;i++)
  {
    scanf("%d",a+i);
  }
  qsort(a,m,4,cmp);
  for(i=0;i<m;i++)
  {
    j=a[i]*MIN(m-i,n);
    if(max<j)
    {
      max=j;
      maxPrice=a[i];
    }
  }
  printf("%d %d",maxPrice,max);
}
